/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:31:48 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/10 14:07:07 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	read_letter(t_ms *ms)
{
	size_t	i;

	i = ms->copied_len;
	while (i < ms->cap)
	{
		if (i == (size_t)ms->bytes_read && (size_t)ms->bytes_read < ms->cap)
		{
			ms->state = GNL_EOF;
			return ;
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
}

void	set_param(t_ms *ms)
{
	ms->copied_len += ms->count;
	ms->state = LETTER;
	ms->tmp_len = 0;
	ms->count = 0;
	free(ms->tmp_buffer);
	ms->tmp_buffer = NULL;
}

void	set_next_line(t_ms *ms, char **next_line)
{
	size_t	i;
	size_t	next_len;

	next_len = ms->count + ms->tmp_len;
	*next_line = malloc(next_len + 1);
	if (!*next_line)
	{
		ms->state = ERROR;
		return ;
	}
	i = 0;
	while (i < ms->tmp_len)
	{
		(*next_line)[i] = (i < ms->tmp_len) * (ms->tmp_buffer)[i];
		i++;
	}
	while (i < next_len)
	{
		(*next_line)[i] = (ms->buffer)[ms->copied_len - ms->tmp_len + i];
		i++;
	}
	(*next_line)[i] = '\0';
	set_param(ms);
}

int	set_tmp_buffer(t_ms *ms)
{
	size_t	i;
	char	*tmp_tmp;
	size_t	tmp_tmp_len;

	tmp_tmp_len = ms->bytes_read - ms->copied_len;
	tmp_tmp = (char *)malloc(ms->tmp_len + tmp_tmp_len + 1);
	if (!tmp_tmp)
		return (-1);
	i = 0;
	while (i < ms->tmp_len)
	{
		tmp_tmp[i] = ms->tmp_buffer[i];
		i++;
	}
	while (i < ms->tmp_len + tmp_tmp_len)
	{
		tmp_tmp[i] = ms->buffer[ms->copied_len - ms->tmp_len + i];
		i++;
	}
	tmp_tmp[i] = '\0';
	free(ms->tmp_buffer);
	ms->tmp_buffer = tmp_tmp;
	ms->tmp_len += tmp_tmp_len;
	return (1);
}

int	re_read(t_ms *ms)
{
	if (set_tmp_buffer(ms) == -1)
	{
		ms->state = ERROR;
		return (-1);
	}
	ms->bytes_read = read(ms->fd, ms->buffer, BUFFER_SIZE);
	if (ms->bytes_read < 0)
	{
		ms->state = ERROR;
		return (-1);
	}
	ms->buffer[ms->bytes_read] = '\0';
	ms->state = LETTER;
	ms->copied_len = 0;
	ms->count = 0;
	return (1);
}
