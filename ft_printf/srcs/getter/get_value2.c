/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:46:33 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/20 18:23:12 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	format->f_num = 1;
	return (ft_uitoa(value));
}

char	*get_hex_value(t_format *format)
{
	unsigned long	value;
	char			*hex;
	char			*hashed_hex;

	value = va_arg(format->args, unsigned long);
	if (value < 0)
	{
		format->sign = -1;
		value *= -1;
	}
	format->f_num = 1;
	hex = convert_to_hex((int)value, format->type);
	if (format->f_sharp && hex[0] != '0')
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
