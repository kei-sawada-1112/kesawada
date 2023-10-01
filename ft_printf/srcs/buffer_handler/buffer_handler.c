/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:11:04 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/01 13:25:44 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

void	init_buffer(t_format *format)
{
	format->buffer = (char *)malloc(BUFFER_SIZE);
	if (!format->buffer)
		return ;
	format->buffer[0] = '\0';
	format->cap = 0;
}

void	add_to_buffer(const char *str, t_format *format)
{
	char	*new_buffer;
	size_t	len_str;
	size_t	len_buffer;

	len_str = ft_strlen(str);
	len_buffer = ft_strlen(format->buffer);
	while (len_buffer + len_str > format->cap)
	{
		format->cap += BUFFER_SIZE;
		new_buffer = (char *)malloc(format->cap);
		ft_strlcpy(new_buffer, format->buffer, len_buffer + 1);
		free(format->buffer);
		format->buffer = new_buffer;
	}
	ft_strlcpy(format->buffer + len_buffer, str, len_str + 1);
}
