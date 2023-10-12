/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:52:23 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/12 14:00:15 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	process_letter(char **str, t_format *format)
{
	size_t	i;

	i = 0;
	while ((*str)[i] && (*str)[i] != '%')
		i++;
	write(1, *str, i);
	format->len += i;
	if (**str == '%')
	{
		format->state = FLAG;
		i++;
	}
	(*str) += i;
}

void	process_field(char **str, t_format *format)
{
	format->width = ft_atoi(*str);
	while (**str >= '0' && **str <= '9')
		(*str)++;
	format->state = FLAG;
}

void	process_prefix(char **str, t_format *format)
{
	format->precision = ft_atoi(*str);
	while (**str >= '0' && **str <= '9')
		(*str)++;
	format->state = FLAG;
}

void	process_type(char **str, t_format *format)
{
	static t_getter	f[] = {
		get_char_value, get_str_value, get_hexaddr_value,
		get_int_value, get_int_value, get_uint_value,
		get_hex_value, get_hex_value, get_per_value, get_char_value
	};

	handle_common(format, f[format->type]);
	format->state = LETTER;
	format->sign = 1;
	format->precision = 0;
	format->width = 0;
	format->f_num = 0;
	format->f_dot = 0;
	format->f_sharp = 0;
	format->f_minus = 0;
	format->f_plus = 0;
	format->f_space = 0;
	format->f_zero = 0;
	format->f_asta = 0;
	free(format->field);
	format->field = NULL;
	free(format->prefix);
	format->prefix = NULL;
	(*str)++;
}
