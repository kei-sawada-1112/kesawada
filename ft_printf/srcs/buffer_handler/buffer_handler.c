/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:11:04 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/08 12:38:06 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	init_buffer(t_format *format)
{
	format->buffer = (char *)malloc(BUFFER_SIZE);
	if (!format->buffer)
		return ;
	format->buffer[0] = '\0';
	format->cap = 0;
}

void	add_null_to_buffer(t_format *format)
{
	char	*new_buffer;

	while (format->len + 1 > format->cap)
	{
		format->cap += BUFFER_SIZE;
		new_buffer = (char *)malloc(format->cap);
		ft_strlcpy(new_buffer, format->buffer, format->len + 1);
		free(format->buffer);
		format->buffer = new_buffer;
	}
	ft_memcpy(new_buffer, "\0", 1);
	format->len += 1;
}

void	add_to_buffer(const char *str, t_format *format)
{
	char	*new_buffer;
	size_t	len_str;

	len_str = ft_strlen(str);
	if (len_str > format->precision && format->type == TYPE_S && format->f_dot)
		len_str = format->precision;
	if (len_str == 0)
		return ;
	while (format->len + len_str > format->cap)
	{
		format->cap += BUFFER_SIZE;
		new_buffer = (char *)malloc(format->cap);
		if (!new_buffer)
		{
			free(format->buffer);
			return ;
		}
		ft_strlcpy(new_buffer, format->buffer, format->len);
		free(format->buffer);
		format->buffer = new_buffer;
	}
	ft_strlcpy(format->buffer + format->len, str, len_str + 1);
	format->len += len_str;
}
