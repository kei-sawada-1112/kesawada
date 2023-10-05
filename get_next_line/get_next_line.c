/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:36:00 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/05 19:37:27 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int	init_ms(t_ms *ms, int fd)
{
	if (!*ms->buffer)
	{
		ms->bytes_read = read(fd, ms->buffer, BUFFER_SIZE);
		if (ms->bytes_read < 0)
			return (-1);
		ms->fd = fd;
	}
	return (1);
}

int	endline_function(t_ms *ms, char **next_line)
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
		else if (ms.state == NEED_READ)
			re_read(&ms);
		else if (ms.state == NEWLINE || ms.state == GNL_EOF)
		{
			if (endline_function(&ms, &next_line) == -1)
				return (NULL);
			break ;
		}
	}
	return (next_line);
}
