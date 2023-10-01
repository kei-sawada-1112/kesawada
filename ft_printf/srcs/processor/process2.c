/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:52:23 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/01 12:39:21 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>

#include <stdio.h>

static int	count_digit(int num)
{
	int	digit;

	digit = 0;
	while (num)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

void	process_field(char **str, t_format *format)
{
	format->width = ft_atoi(*str);
	*str += count_digit(format->width);
	format->state = FLAG;
}

void	process_prefix(char **str, t_format *format)
{
	format->precision = ft_atoi(*str);
	*str += count_digit(format->width);
	format->state = FLAG;
}

void	process_type(char **str, t_format *format)
{
	static f_getter f[] =
	{
		get_char_value, get_str_value, get_hex_value, get_int_value, get_int_value,
		get_uint_value, get_str_value, get_str_value, get_per_value
		//handle_u, handle_x, handle_X, handle_per
	};
	handle_common(format, f[format->type]);
	init_format(format);
	(*str)++;
}

void	process_error(char **str, t_format *format)
{
	(void) str;
	(void) format;

	write(1, "Invalid format\n", 15);
	format->state = LETTER;
}
