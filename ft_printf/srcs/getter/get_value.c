/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:59:16 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/07 14:34:49 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

char	*get_int_value(t_format *format)
{
	int	value;
	value = va_arg(format->args, int);
	format->f_num = 1;
	if (value < 0)
	{
		if (value != INT_MIN)
		{
			value *= -1;
			format->sign = -1;
		}
		format->f_plus = 0;
	}
	return (ft_itoa((int)value));
}

char	*get_double_value(t_format *format)
{
	double	value;

	value = va_arg(format->args, double);
	format->f_num = 1;
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
	if (!value)
		return (ft_strdup("0x0"));
	return (convert_to_hexaddr(value));
}
