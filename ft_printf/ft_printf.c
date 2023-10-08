/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:04:29 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/08 12:04:32 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void	state_based_process(char **str, t_format *format)
{
	static t_process	f[] = {
		process_letter, process_flag, process_field,
		process_prefix, process_type, process_error
	};

	f[format->state](str, format);
}

void	init_format(t_format *format)
{
	format->state = LETTER;
	format->cap = BUFFER_SIZE;
	format->len = 0;
	format->f_hash = 0;
	format->f_minus = 0;
	format->f_plus = 0;
	format->f_space = 0;
	format->f_zero = 0;
	format->f_dot = 0;
	format->f_num = 0;
	format->prefix = NULL;
	format->field = NULL;
	format->type = 0;
	format->width = 0;
	format->precision = 0;
	format->sign = 1;
}

int	ft_printf(const char *input, ...)
{
	t_format	format;

	va_start(format.args, input);
	init_buffer(&format);
	init_format(&format);
	while (*input)
		state_based_process((char **)(&input), &format);
	write(1, format.buffer, format.len);
	va_end(format.args);
	free(format.buffer);
	return (format.len);
}
