/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:36:00 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/10 14:10:25 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	free_all(t_ms *dummy, t_ms *ms)
{
	t_ms	*prev;

	free(ms->tmp_buffer);
	ms->tmp_buffer = NULL;
	free(ms->buffer);
	ms->buffer = NULL;
	prev = dummy;
	while (prev->next && prev->next != ms)
		prev = prev->next;
	if (prev->next)
		prev->next = ms->next;
	free(ms);
}

static t_ms	*init_ms(int fd)
{
	t_ms	*new;

	new = malloc(sizeof(t_ms));
	if (!new)
		return (NULL);
	*new = (t_ms){0};
	new->fd = fd;
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
	return (new);
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

int	state_based_process(t_ms *dummy, t_ms *ms, char **next_line)
{
	if (ms->state == LETTER)
		read_letter(ms);
	else if (ms->state == NEED_READ)
		re_read(ms);
	else if (ms->state == NEWLINE || ms->state == GNL_EOF)
	{
		if (!ms->count && !ms->tmp_len)
		{
			free_all(dummy, ms);
			return (-1);
		}
		set_next_line(ms, next_line);
		return (1);
	}
	else if (ms->state == ERROR)
	{
		free_all(dummy, ms);
		return (-1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_ms	dummy;
	char		*next_line;
	t_ms		*c_ms;
	int			output;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dummy.fd = INT_MIN;
	c_ms = get_current_ms(&dummy, fd);
	if (!c_ms)
		return (NULL);
	while (1)
	{
		output = state_based_process(&dummy, c_ms, &next_line);
		if (output == 1)
			return (next_line);
		if (output == -1)
			return (NULL);
	}
	return (next_line);
}
