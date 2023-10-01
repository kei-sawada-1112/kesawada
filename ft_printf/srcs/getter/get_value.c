/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:59:16 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/01 12:41:55 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

char	*get_int_value(t_format *format)
{
	int	value;

	value = va_arg(format->args, int);
	if (value < 0)
		format->sign = -1;
	if (format->f_zero)
		value *= -1;
	return (ft_itoa(value));
}

char	*get_double_value(t_format *format)
{
	double	value;

	value = va_arg(format->args, double);
	if (value < 0)
		format->sign = -1;
	if (format->f_zero)
		value *= -1;
	return (ft_itoa((int)value));
}

char	*get_char_value(t_format *format)
{
	char	*value;

	value = (char *)malloc(2);
	if (!value)
		return (NULL);
	value[0] = va_arg(format->args, int);
	value[1] = '\0';
	return (value);
}

char	*get_str_value(t_format *format)
{
	return (ft_strdup(va_arg(format->args, char *)));
}

char	*get_hex_value(t_format *format)
{
	char	*value;

	value = va_arg(format->args, char *);
	return (convert_to_hex(value));
}

char	*get_per_value(t_format *format)
{
	char	*value;

	value = malloc(2);
	(void)format;
	if (!value)
		return (NULL);
	value[0] = '%';
	value[1] = '\0';
	return (value);
}

char	*get_uint_value(t_format *format)
{
	unsigned int	value;

	value = va_arg(format->args, unsigned int);
	return (ft_itoa(value));
}
