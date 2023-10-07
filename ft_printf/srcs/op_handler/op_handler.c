/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:22:06 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/07 14:51:53 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#include <stdio.h>

static void	check_field(t_format *format, char *value)
{
	long long	field_len;

	if (format->f_zero && format->sign == -1 && !format->f_dot)
		add_to_buffer("-", format);
	if (format->precision < ft_strlen(value) && format->f_dot)
		field_len = format->width - format->precision;
	else
		field_len = format->width - ft_strlen(value);
	if (format->sign == -1)
		field_len -= 1;
	if (field_len > 0 && !format->f_dot)
	{
		format->field = malloc(field_len + 1);
		if (!format->field)
			return ;
		if (format->f_zero || format->f_dot)
			ft_memset(format->field, '0', field_len);
		else
			ft_memset(format->field, ' ', field_len);
		format->field[field_len] = '\0';
	}
	else if (format->f_space && format->sign == 1)
		add_to_buffer(" ", format);
	if (!format->f_zero && format->sign == -1)
		add_to_buffer("-", format);
}

void	handle_common(t_format *format, char *(*get_value)(t_format *))
{
	char	*value;

	value = get_value(format);
	if (value[0] == '\0' && format->type == TYPE_C)
		format->width -= 1;
	if (format->f_plus)
		add_to_buffer("+", format);
	else
		check_field(format, value);
	if (value)
	{
		if (!format->f_minus && format->field)
		{
			add_to_buffer(format->field, format);
			free(format->field);
		}
		if (value[0] == '\0' && format->type == TYPE_C)
			add_null_to_buffer(format);
		add_to_buffer(value, format);
		if (format->f_minus && format->field)
		{
			add_to_buffer(format->field, format);
			free(format->field);
		}
		free(value);
	}
}
