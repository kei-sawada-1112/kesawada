/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:59:16 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/01 01:38:15 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

char	*get_int_value(t_format *format)
{
	int	value;

	value = va_arg(format->args, int);
	return (ft_itoa(value));
}

char	*get_double_value(t_format *format)
{
	double	value;

	value = va_arg(format->args, double);
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
	char	*str;

	str = va_arg(format->args, char *);
	return (convert_to_hex(str));
}
