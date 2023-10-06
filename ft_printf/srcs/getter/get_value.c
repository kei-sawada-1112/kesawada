/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:59:16 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/06 20:44:24 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

#include <limits.h>

#include <stdio.h>

char	*get_int_value(t_format *format)
{
	int	value;
	value = va_arg(format->args, int);
	if (value < 0 && value != INT_MIN)
	{
		format->sign = -1;
		value *= -1;
	}
	return (ft_itoa((int)value));
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
	return (ft_itoa((double)value));
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
	char	*value;

	value = va_arg(format->args, char *);
	if (!value)
		return (ft_strdup("(null)"));
	else
		return (ft_strdup(value));
}

char	*get_hexaddr_value(t_format *format)
{
	char	*value;

	value = va_arg(format->args, char *);
	return (convert_to_hexaddr(value));
}
