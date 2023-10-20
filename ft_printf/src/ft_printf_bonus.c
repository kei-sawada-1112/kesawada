/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:04:29 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/21 06:23:16 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	state_based_process(const char **str, t_format *format)
{
	static t_process	f[] = {
		process_letter, process_flag, process_field,
		process_prefix, process_type
	};

	f[format->state](str, format);
}

void	init_format(t_format *format)
{
	format->state = LETTER;
	format->type = TYPE_C;
	format->len = 0;
	format->f_sharp = 0;
	format->f_minus = 0;
	format->f_plus = 0;
	format->f_space = 0;
	format->f_zero = 0;
	format->f_dot = 0;
	format->f_num = 0;
	format->f_asta = 0;
	format->field = NULL;
	format->width = 0;
	format->prefix = NULL;
	format->precision = 0;
	format->type = 0;
	format->sign = 1;
	format->invalid_char = 0;
}

int	ft_printf(const char *input, ...)
{
	t_format	format;

	va_start(format.args, input);
	init_format(&format);
	while (*input)
		state_based_process(&input, &format);
	va_end(format.args);
	return (format.len);
}
