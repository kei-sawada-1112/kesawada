/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:31:48 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/02 20:35:04 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

void print_state(t_ms *ms)
{
    printf("State: %d\n", ms->state);
	printf("count: %zu\n", ms->count);
	printf("copied_len: %zu\n", ms->copied_len);
    printf("tmp_len: %zu\n", ms->tmp_len);
	printf("start_pos: %zu\n", ms->start_pos);
	printf("capacity: %zu\n", ms->capacity);
    printf("bytes_read: %zu\n", ms->bytes_read);
    printf("--------------------\n");
}

void	read_letter(t_ms *ms)
{
	size_t	i;

	printf("---read_letter---\n");
	i = ms->start_pos;
	while (i < ms->bytes_read)
	{
		if (ms->buffer[i] == '\0')
		{
			ms->state = EOF;
			return;
		}
		else if (ms->buffer[i] == '\n')
		{
			if (ms->buffer[i - 1] == '\n')
				ms->count = 1;
			else
				ms->count++;
			ms->state = NEWLINE;
			return ;
		}
		ms->count++;
		i++;
	}
	ms->state = NEED_READ;
	print_state(ms);
	printf("---read_letter_end---\n");
}

void	set_next_line(t_ms *ms, char **next_line)
{
	size_t	i;
	size_t	next_len;

	printf("---set_next_line---\n");
	print_state(ms);
	next_len = ms->count + ms->tmp_len;
	*next_line = malloc(next_len + 1);
	i = 0;
	while (i < next_len)
	{
		(*next_line)[i] = (ms->buffer)[ms->copied_len + i];
		i++;
	}
	(*next_line)[i] = '\0';
	if (ms->copied_len == 0)
		ms->copied_len = 1;
	ms->copied_len += next_len;
	ms->start_pos = ms->copied_len;
	ms->state = LETTER;
	ms->count = 0;
	ms->tmp_len = 0;
	print_state(ms);
	printf("---set_next_line_end---\n");
}

void	set_tmp_buffer(t_ms *ms)
{
	size_t	i;

	printf("---set_tmp_buffer---\n");
	i = 0;
	ms->tmp_len = ms->bytes_read - ms->copied_len;
	ms->tmp_buffer = (char *)malloc(ms->tmp_len + 1);
	while (i < ms->tmp_len)
	{
		ms->tmp_buffer[i] = ms->buffer[ms->copied_len + i];
		i++;
	}
	ms->tmp_buffer[i] = '\0';
	print_state(ms);
	printf("---set_tmp_buffer_end---\n");
}

void	re_read(t_ms *ms, int fd)
{
	size_t	i;

	printf("---re_read---\n");
	print_state(ms);
	free(ms->buffer);
	ms->capacity += BUFFER_SIZE;
	ms->buffer = (char *)malloc(ms->capacity + 1);
	i = 0;
	while (i < ms->tmp_len)
	{
		ms->buffer[i] = ms->tmp_buffer[i];
		i++;
	}
	ms->bytes_read = read(fd, ms->buffer + ms->tmp_len, ms->capacity - ms->tmp_len);
	ms->buffer[ms->bytes_read] = '\0';
	free(ms->tmp_buffer);
	ms->state = LETTER;
	ms->start_pos = ms->tmp_len;
	ms->count = 0;
	print_state(ms);
	printf("---re_read_end---\n");
}
