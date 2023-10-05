/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:36:00 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/05 16:12:40 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <limits.h>

#include <string.h>

void	reset_param(t_ms *ms, int fd)
{
	ms->fd = fd;
	ms->state = LETTER;
	ms->count = 0;
	ms->copied_len = 0;
	ms->start_pos = 0;
	ms->tmp_buffer = NULL;
	ms->tmp_len = 0;
}

int	init_ms(t_ms *ms, int fd)
{
	if (!*ms->buffer)
	{
		ms->bytes_read = read(fd, ms->buffer, BUFFER_SIZE);
		if (ms->bytes_read < 0)
			return (-1);
		reset_param(ms, fd);
	}
	return (1);
}

int	eof_function(t_ms *ms, char **next_line)
{
	if (!ms->count && !ms->tmp_len)
	{
		if (ms->tmp_buffer)
			free(ms->tmp_buffer);
		return (-1);
	}
	set_next_line(ms, next_line);
	return (1);
}

char	*get_next_line(int fd)
{
	static t_ms	ms;
	char		*next_line;

	if (BUFFER_SIZE == 0 || fd < 0 || init_ms(&ms, fd) == -1)
		return (NULL);
	while (1)
	{
		if (ms.state == LETTER)
			read_letter(&ms);
		else if (ms.state == NEWLINE)
		{
			set_next_line(&ms, &next_line);
			break ;
		}
		else if (ms.state == NEED_READ)
			re_read(&ms);
		else if (ms.state == GNL_EOF)
		{
			if (eof_function(&ms, &next_line) == -1)
				return (NULL);
			break ;
		}
	}
	return (next_line);
}
