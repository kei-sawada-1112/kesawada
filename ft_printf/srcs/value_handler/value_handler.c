/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:22:06 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/08 23:28:47 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

static long long	set_field_len(t_format *format, char *value)
{
	long long	field_len;

	if (format->f_dot)
	{
		if (!format->f_num)
			field_len = ((format->width - ft_strlen(value))
					* (ft_strlen(value) < format->precision)
					+ (format->width - format->precision)
					* (ft_strlen(value) >= format->precision));
		else
			field_len = ((format->width - ft_strlen(value))
					* (ft_strlen(value) > format->precision)
					+ (format->width - format->precision)
					* (ft_strlen(value) <= format->precision)
					+ (value[0] == '0' && format->precision == 0));
	}
	else
		field_len = (format->width - ft_strlen(value));
	if (format->f_space && format->sign == 1 && format->f_num)
	{
		add_to_buffer(" ", format);
		field_len -= 1;
	}
	return (field_len);
}

static void	check_field(t_format *format, char *value)
{
	long long	field_len;

	if (format->precision > format->width && format->f_num)
		return ;
	if (format->f_minus)
		format->f_zero = 0;
	if (format->precision > 0 && format->f_num)
		format->f_zero = 0;
	field_len = set_field_len(format, value);
	if (format->sign == -1)
		field_len -= 1;
	if (field_len > 0)
	{
		format->field = malloc(field_len + 1);
		if (!format->field)
			return ;
		if ((format->f_zero && !format->f_dot))
			ft_memset(format->field, '0', field_len);
		else
			ft_memset(format->field, ' ', field_len);
		format->field[field_len] = '\0';
	}
}

static void	check_prefix(t_format *format, char *value)
{
	long long	prefix_len;

	if (ft_strlen(value) == 0 || format->precision < ft_strlen(value))
		return ;
	prefix_len = format->precision - ft_strlen(value);
	if (prefix_len > 0)
	{
		format->prefix = malloc(prefix_len + 1);
		if (!format->prefix)
			return ;
		ft_memset(format->prefix, '0', prefix_len);
		format->prefix[prefix_len] = '\0';
	}
}

static void	add_buffer_and_free(t_format *format, char *value)
{
	if (!format->f_dot && (format->f_zero && !format->f_dot)
		&& format->sign == -1)
		add_to_buffer("-", format);
	if (!format->f_minus && format->field)
	{
		add_field_or_prefix(format->field, format);
		free(format->field);
	}
	if (!(!format->f_dot && (format->f_zero && !format->f_dot))
		&& format->sign == -1)
		add_to_buffer("-", format);
	if (format->prefix)
	{
		add_field_or_prefix(format->prefix, format);
		free(format->prefix);
	}
	if (value[0] == '\0' && format->type == TYPE_C)
		add_null_to_buffer(format);
	add_to_buffer(value, format);
	if (format->f_minus && format->field)
	{
		add_field_or_prefix(format->field, format);
		free(format->field);
	}
	free(value);
}

void	handle_common(t_format *format, char *(*get_value)(t_format *))
{
	char	*value;

	value = get_value(format);
	if (value[0] == '\0' && format->type == TYPE_C)
		format->width -= 1;
	if (format->f_dot && format->precision == 0 && !format->f_num)
	{
		add_space_to_buffer(format);
		free (value);
		return ;
	}
	if (format->f_plus)
		add_to_buffer("+", format);
	else
		check_field(format, value);
	if (format->f_dot && format->f_num)
		check_prefix(format, value);
	if (value)
		add_buffer_and_free(format, value);
}
