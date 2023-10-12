/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:22:06 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/12 14:00:50 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static long long	set_field_len(t_format *format, char *value)
{
	long long	field_len;

	if (format->f_dot)
	{
		if (!format->f_num && format->type != TYPE_P && format->precision != 0)
			field_len = ((format->width - ft_strlen(value))
					* (ft_strlen(value) < format->precision)
					+ (format->width - format->precision)
					* (ft_strlen(value) >= format->precision));
		else
			field_len = ((format->width - ft_strlen(value))
					* (ft_strlen(value) > format->precision)
					+ (format->width - format->precision)
					* (ft_strlen(value) <= format->precision))
				+ (value[0] == '0' && format->precision == 0);
	}
	else
		field_len = (format->width - ft_strlen(value));
	if (format->f_space && format->sign == 1
		&& !format->f_plus && format->f_num)
	{
		putstr_and_add_len(" ", format);
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
	if (format->type == TYPE_P)
		field_len -= 2;
	if (format->sign == -1 || format->f_plus)
		field_len -= 1;
	if (field_len > 0)
	{
		format->field = malloc(field_len + 1);
		if (!format->field)
			return ;
		if (format->f_zero)
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

static void	write_value(t_format *format, char *value)
{
	if (!format->f_dot && (format->f_zero && !format->f_dot)
		&& format->sign == -1)
		putstr_and_add_len("-", format);
	if (!format->f_minus && format->field)
		apply_padding(format->field, format);
	if (!(!format->f_dot && (format->f_zero && !format->f_dot))
		&& format->sign == -1)
		putstr_and_add_len("-", format);
	if (format->f_plus)
		putstr_and_add_len("+", format);
	if (format->prefix)
		putstr_and_add_len(format->prefix, format);
	if (value[0] == '\0' && format->type == TYPE_C)
	{
		write(1, "\0", 1);
		format->len += 1;
	}
	if (format->type == TYPE_P)
		putstr_and_add_len("0x", format);
	putstr_and_add_len(value, format);
	if (format->f_minus && format->field)
		apply_padding(format->field, format);
	free (value);
}

void	handle_common(t_format *format, char *(*get_value)(t_format *))
{
	char	*value;

	value = get_value(format);
	if (value[0] == '\0' && format->type == TYPE_C)
		format->width -= 1;
	if (format->f_dot && format->precision == 0)
	{
		if ((format->f_num && value[0] == '0') || ((format->type != TYPE_P)
				&& !format->f_num && (format->type != TYPE_PER)))
		{
			free(value);
			value = ft_strdup("\0");
		}
	}
	check_field(format, value);
	if (format->f_dot && (format->f_num || format->type == TYPE_P))
		check_prefix(format, value);
	if (value)
		write_value(format, value);
}
