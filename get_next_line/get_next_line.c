/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:36:00 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/16 17:27:42 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	init_ms(t_ms *ms, int fd)
{
	ms->buffer = malloc(BUFFER_SIZE + 1);
	if (!ms->buffer)
		return (0);
	ms->bytes_read = read(fd, ms->buffer, BUFFER_SIZE);
	if (ms->bytes_read < 0)
	{
		free(ms->buffer);
		return (0);
	}
	ms->buffer[ms->bytes_read] = '\0';
	ms->used = 1;
	ms->fd = fd;
	return (1);
}

int	endline_function(t_ms *ms, char **next_line)
{
	if (!ms->count && !ms->tmp_len)
	{
		if (ms->tmp_buffer)
		{
			free(ms->tmp_buffer);
			ms->tmp_buffer = NULL;
		}
		if (ms->buffer)
		{
			free(ms->buffer);
			ms->buffer = NULL;
		}
		return (-1);
	}
	set_next_line(ms, next_line);
	return (1);
}

char	*get_next_line(int fd)
{
	static t_ms	ms[OPEN_MAX];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	if (!ms[fd].used)
	{
		if (!init_ms(&ms[fd], fd))
			return (NULL);
	}
	while (1)
	{
		if (ms[fd].state == LETTER)
			read_letter(&ms[fd]);
		else if (ms[fd].state == NEED_READ)
			re_read(&ms[fd]);
		else if (ms[fd].state == NEWLINE || ms[fd].state == GNL_EOF)
		{
			if (endline_function(&ms[fd], &next_line) == -1)
				return (NULL);
			break ;
		}
	}
	return (next_line);
}
