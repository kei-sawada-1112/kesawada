/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:52:23 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/10 13:24:32 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	*str += count_digit(format->precision);
	format->state = FLAG;
}

void	process_type(char **str, t_format *format)
{
	static t_getter	f[] = {
		get_char_value, get_str_value, get_hexaddr_value,
		get_int_value, get_int_value, get_uint_value,
		get_hex_value, get_hex_value, get_per_value
	};

	handle_common(format, f[format->type]);
	format->state = LETTER;
	format->sign = 1;
	format->precision = 0;
	format->width = 0;
	format->f_num = 0;
	format->f_dot = 0;
	format->f_hash = 0;
	format->f_minus = 0;
	format->f_plus = 0;
	format->f_space = 0;
	format->f_zero = 0;
	free(format->field);
	format->field = NULL;
	free(format->prefix);
	format->prefix = NULL;
	(*str)++;
}

void	process_error(char **str, t_format *format)
{
	(void) str;
	(void) format;
	write(1, "Invalid format\n", 15);
	format->state = LETTER;
}
