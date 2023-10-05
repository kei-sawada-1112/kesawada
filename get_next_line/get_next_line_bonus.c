/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:36:00 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/05 19:37:43 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>

t_ms	*get_current_ms(t_ms *ms, int fd)
{
	int	i;

	i = 0;
	while (ms[i].used == 1)
	{
		if (ms[i].fd == fd)
			return (&ms[i]);
		i++;
	}
	if (!*ms[i].buffer)
	{
		ms[i].bytes_read = read(fd, ms[i].buffer, BUFFER_SIZE);
		if (ms[i].bytes_read < 0)
			return (NULL);
		ms[i].fd = fd;
		ms[i].used = 1;
	}
	return (&ms[i]);
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
	static t_ms	ms[100];
	char		*next_line;
	t_ms		*current_ms;

	current_ms = get_current_ms(ms, fd);
	if (!current_ms || BUFFER_SIZE == 0 || fd < 0)
		return (NULL);
	while (1)
	{
		if (current_ms->state == LETTER)
			read_letter(current_ms);
		else if (current_ms->state == NEED_READ)
			re_read(current_ms);
		else if (current_ms->state == NEWLINE || current_ms->state == GNL_EOF)
		{
			if (endline_function(current_ms, &next_line) == -1)
				return (NULL);
			break ;
		}
	}
	return (next_line);
}
