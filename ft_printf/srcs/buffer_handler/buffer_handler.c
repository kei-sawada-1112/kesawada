/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:11:04 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/09 00:29:42 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

#include <stdio.h>

void	add_null_to_buffer(t_format *format)
{
	char	*new_buffer;

	while (format->len + 1 > format->cap)
	{
		format->cap += BUFFER_SIZE;
		new_buffer = (char *)malloc(format->cap);
		if (!new_buffer)
			return ;
		ft_strlcpy(new_buffer, format->buffer, format->len + 1);
		free(format->buffer);
		format->buffer = new_buffer;
	}
	ft_memcpy(new_buffer, "\0", 1);
	format->len += 1;
}

void	add_space_to_buffer(t_format *format)
{
	char	*new_buffer;

	{
		format->cap += BUFFER_SIZE;
		new_buffer = (char *)malloc(format->cap);
		if (!new_buffer)
		{
			free(format->buffer);
			return ;
		}
		ft_strlcpy(new_buffer, format->buffer, format->len + 1);
		free(format->buffer);
		format->buffer = new_buffer;
	}
	ft_memset(format->buffer + format->len, ' ', format->width);
	format->len += format->width;
}

void	add_field_or_prefix(const char *str, t_format *format)
{
	char	*new_buffer;
	size_t	len_str;

	len_str = ft_strlen(str);
	while (format->len + len_str > format->cap)
	{
		format->cap += BUFFER_SIZE;
		new_buffer = (char *)malloc(format->cap);
		if (!new_buffer)
		{
			free(format->buffer);
			return ;
		}
		ft_strlcpy(new_buffer, format->buffer, format->len + 1);
		free(format->buffer);
		format->buffer = new_buffer;
	}
	ft_strlcpy(format->buffer + format->len, str, len_str + 1);
	format->len += len_str;
}

void	add_to_buffer(const char *str, t_format *format)
{
	char	*new_buffer;
	size_t	len_str;

	len_str = ft_strlen(str);
	if (len_str == 0 || ((format->f_num && !ft_strncmp(str, "0", 1)
				&& format->f_dot && format->precision == 0)))
		return ;
	if (len_str > format->precision && format->f_dot
		&& !format->f_num && format->type != TYPE_P)
		len_str = format->precision;
	while (format->len + len_str > format->cap)
	{
		format->cap += BUFFER_SIZE;
		new_buffer = (char *)malloc(format->cap);
		if (!new_buffer)
		{
			free(format->buffer);
			return ;
		}
		ft_strlcpy(new_buffer, format->buffer, format->len + 1);
		free(format->buffer);
		format->buffer = new_buffer;
	}
	ft_strlcpy(format->buffer + format->len, str, len_str + 1);
	format->len += len_str;
}
