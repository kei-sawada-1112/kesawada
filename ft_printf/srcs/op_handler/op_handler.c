/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:22:06 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/01 01:42:56 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include <stdarg.h>

#include <stdio.h>

static void	check_space(t_format *format)
{
	char	*space;
	int		space_len;

	space_len = format->width - ft_strlen(format->buffer) - 1;
	space = malloc(space_len + 1);
	if (!space)
		return ;
	if (format->width != 0 && space_len > 0)
	{
		space = ft_memset(space, ' ', space_len);
		space[space_len] = '\0';
		add_to_buffer(space, format);
	}
	free(space);
}

void	handle_common(t_format *format, char *(*get_value)(t_format *))
{
	char	*value;

	if (format->f_plus)
		add_to_buffer("+", format);
	else
		check_space(format);
	value = get_value(format);
	if (value)
	{
		add_to_buffer(value, format);
		free(value);
	}
}
