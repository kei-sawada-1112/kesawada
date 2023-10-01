/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:22:06 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/01 12:42:58 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#include <stdio.h>

static void	check_field(t_format *format)
{
	char	*field;
	int		field_len;

	field = NULL;
	field_len = format->width - ft_strlen(format->buffer) - 1;
	printf("width: %zu\n", format->width);
	if (field_len > 0)
	{
		field = malloc(field_len + 1);
		if (!field)
			return ;
		if (format->f_zero)
		{
			if (format->sign == -1)
			{
				field[0] = '-';
				ft_memset(field + 1, '0', field_len - 1);
			}
			else
				field = ft_memset(field, '0', field_len);
		}
		else
			field = ft_memset(field, ' ', field_len);
		field[field_len] = '\0';
		add_to_buffer(field, format);
		free(field);
	}
	else if (format->f_space && format->sign == 1)
		add_to_buffer(" ", format);
	else
		format->f_zero = 0;
}

void	handle_common(t_format *format, char *(*get_value)(t_format *))
{
	char	*value;

	if (format->f_plus)
		add_to_buffer("+", format);
	else
		check_field(format);
	value = get_value(format);
	if (value)
	{
		add_to_buffer(value, format);
		free(value);
	}
}
