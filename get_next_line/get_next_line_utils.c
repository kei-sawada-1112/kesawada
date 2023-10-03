/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:31:48 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/03 13:04:06 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

void print_state(t_ms *ms)
{
    printf("state: %d\n", ms->state);
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

	// printf("---read_letter---\n");
	i = ms->start_pos;
	while (i < ms->capacity)
	{
		if (i == ms->bytes_read + ms->start_pos)
		{
			ms->state = EOF;
			return;
		}
		else if (ms->buffer[i] == '\n')
		{
			ms->count++;
			ms->state = NEWLINE;
			return ;
		}
		ms->count++;
		i++;
	}
	ms->state = NEED_READ;
	// print_state(ms);
	// printf("---read_letter_end---\n");
}

void	set_next_line(t_ms *ms, char **next_line)
{
	size_t	i;
	size_t	next_len;

	// printf("---set_next_line---\n");
	// print_state(ms);
	next_len = ms->count + ms->tmp_len;
	*next_line = malloc(next_len + ms->tmp_len + 1);
	i = 0;
	while (i < ms->tmp_len)
	{
		(*next_line)[i] = (ms->tmp_buffer)[i];
		i++;
	}
	while (i < next_len)
	{
		(*next_line)[i] = (ms->buffer)[ms->copied_len + i - ms->tmp_len];
		i++;
	}
	(*next_line)[i] = '\0';
	ms->copied_len += ms->count;
	ms->start_pos = ms->copied_len;
	ms->state = LETTER;
	ms->tmp_len = 0;
	ms->count = 0;
	// print_state(ms);
	// printf("---set_next_line_end---\n");
}

void	set_tmp_buffer(t_ms *ms)
{
	size_t	i;
	char	*tmp_tmp;
	size_t	tmp_tmp_len;

	// printf("---set_tmp_buffer---\n");
	tmp_tmp_len = ms->bytes_read - ms->copied_len;
	tmp_tmp = (char *)malloc(ms->tmp_len + tmp_tmp_len + 1);
	i = 0;
	while (i < ms->tmp_len)
	{
		tmp_tmp[i] = ms->tmp_buffer[i];
		i++;
	}
	while (i < tmp_tmp_len + ms->tmp_len)
	{
		tmp_tmp[i] = ms->buffer[ms->copied_len + i - ms->tmp_len];
		i++;
	}
	tmp_tmp[i] = '\0';
	free(ms->tmp_buffer);
	ms->tmp_buffer = tmp_tmp;
	ms->tmp_len += tmp_tmp_len;
	ms->copied_len = 0;
	// print_state(ms);
	// printf("---set_tmp_buffer_end---\n");
}

void	re_read(t_ms *ms, int fd)
{
	// printf("---re_read---\n");
	// print_state(ms);
	free(ms->buffer);
	ms->capacity += BUFFER_SIZE;
	ms->buffer = (char *)malloc(ms->capacity + 1);
	ms->bytes_read = read(fd, ms->buffer, ms->capacity);
	ms->buffer[ms->capacity] = '\0';
	ms->state = LETTER;
	ms->start_pos = 0;
	ms->copied_len = 0;
	ms->count = 0;
	// print_state(ms);
	// printf("---re_read_end---\n");
}
