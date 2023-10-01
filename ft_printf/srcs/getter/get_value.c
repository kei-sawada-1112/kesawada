/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:59:16 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/01 16:23:16 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

#include <stdio.h>

char	*get_int_value(t_format *format)
{
	int	value;

	value = va_arg(format->args, int);
	if (value < 0)
	{
		format->sign = -1;
		value *= -1;
	}
	return (ft_itoa(value));
}

char	*get_double_value(t_format *format)
{
	double	value;

	value = va_arg(format->args, double);
	if (value < 0)
	{
		format->sign = -1;
		value *= -1;
	}
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

char	*get_hexaddr_value(t_format *format)
{
	char	*value;

	value = va_arg(format->args, char *);
	return (convert_to_hexaddr(value));
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

char	*get_hex_value(t_format *format)
{
	long long	value;
	char		*hex;
	char		*hashed_hex;

	value = va_arg(format->args, long long);
	if (value < 0)
	{
		format->sign = -1;
		value *= -1;
	}
	hex = convert_to_hex((int)value, format->type);
	if (format->f_hash)
	{
		if (format->type == TYPE_X)
			hashed_hex = ft_strjoin("0x", hex);
		else
			hashed_hex = ft_strjoin("0X", hex);
		free(hex);
		return (hashed_hex);
	}
	else
		return (hex);
}
