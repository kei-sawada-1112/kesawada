/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:36:00 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/08 20:35:19 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	init_param(t_ms *new, int fd)
{
	new->fd = fd;
	new->state = LETTER;
	new->tmp_buffer = NULL;
	new->cap = BUFFER_SIZE;
	new->tmp_len = 0;
	new->copied_len = 0;
	new->count = 0;
	new->next = NULL;
}

static t_ms	*init_ms(int fd)
{
	t_ms	*new;

	new = malloc(sizeof(t_ms));
	if (!new)
		return (NULL);
	new->cap = BUFFER_SIZE;
	new->buffer = malloc(BUFFER_SIZE + 1);
	if (!new->buffer)
	{
		free(new);
		return (NULL);
	}
	new->bytes_read = read(fd, new->buffer, BUFFER_SIZE);
	if (new->bytes_read < 0)
	{
		free(new->buffer);
		free(new);
		return (NULL);
	}
	new->buffer[new->bytes_read] = '\0';
	init_param(new, fd);
	return (new);
}

static int	endline_function(t_ms *dummy, t_ms *ms, char **next_line)
{
	t_ms	*prev;

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
		prev = dummy;
		while (prev->next && prev->next != ms)
			prev = prev->next;
		if (prev->next)
			prev->next = ms->next;
		free(ms);
		return (0);
	}
	set_next_line(ms, next_line);
	return (1);
}

static t_ms	*get_current_ms(t_ms *ms, int fd)
{
	t_ms	*current;
	t_ms	*prev;

	current = ms;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		prev = current;
		current = current->next;
	}
	current = init_ms(fd);
	prev->next = current;
	return (current);
}

char	*get_next_line(int fd)
{
	static t_ms	dummy;
	char		*next_line;
	t_ms		*c_ms;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dummy.fd = INT_MIN;
	c_ms = get_current_ms(&dummy, fd);
	if (!c_ms)
		return (NULL);
	while (1)
	{
		if (c_ms->state == LETTER)
			read_letter(c_ms);
		else if (c_ms->state == NEED_READ)
		{
			if (re_read(c_ms) == -1)
				return (NULL);
		}
		else if (c_ms->state == NEWLINE || c_ms->state == GNL_EOF)
		{
			if (!endline_function(&dummy, c_ms, &next_line))
				return (NULL);
			break ;
		}
	}
	return (next_line);
}
