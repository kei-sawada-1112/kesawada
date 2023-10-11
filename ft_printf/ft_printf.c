/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:04:29 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/11 13:57:37 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	state_based_process(char **str, t_format *format)
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
	format->len = 0;
	format->f_hash = 0;
	format->f_minus = 0;
	format->f_plus = 0;
	format->f_space = 0;
	format->f_zero = 0;
	format->f_dot = 0;
	format->f_num = 0;
	format->prefix = NULL;
	format->precision = 0;
	format->field = NULL;
	format->width = 0;
	format->type = 0;
	format->sign = 1;
}

int	ft_printf(const char *input, ...)
{
	t_format	format;

	va_start(format.args, input);
	init_format(&format);
	while (*input)
		state_based_process((char **)(&input), &format);
	va_end(format.args);
	return (format.len);
}
