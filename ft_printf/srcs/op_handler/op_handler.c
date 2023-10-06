/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:22:06 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/06 20:41:27 by kesawada         ###   ########.fr       */
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
	char	*field;
	int		field_len;

	if (format->f_zero && format->sign == -1)
		add_to_buffer("-", format);
	field_len = format->width - ft_strlen(value);
	if (format->sign == -1)
		field_len -= 1;
	if (field_len > 0)
	{
		field = malloc(field_len);
		if (!field)
			return ;
		if (format->f_zero)
			ft_memset(field, '0', field_len);
		else
			ft_memset(field, ' ', field_len);
		field[field_len] = '\0';
		add_to_buffer(field, format);
		free(field);
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
		add_null_to_buffer(format);
	if (format->f_plus)
		add_to_buffer("+", format);
	else
		check_field(format, value);
	if (value)
	{
		add_to_buffer(value, format);
		free(value);
	}
}
