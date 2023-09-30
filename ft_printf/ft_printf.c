/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:45:33 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/01 01:40:46 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

#include <stdio.h>

void	state_based_process(char **str, t_format *format)
{
	static f_process f[] =
	{
		process_letter, process_flag, process_field,
		process_prefix, process_type, process_error
	};

	f[format->state](str, format);
}

void	init_format(t_format *format)
{
	init_buffer(format);
	format->state = LETTER;
	format->f_hash = 0;
	format->f_minus = 0;
	format->f_plus = 0;
	format->f_space = 0;
	format->f_zero = 0;
	format->precision = 0;
	format->prefix = 0;
	format->type = 0;
	format->width = 0;
}

int	ft_printf(const char *input, ...)
{
	t_format		format;

	va_start(format.args, input);
	init_format(&format);
	while (*input)
		state_based_process((char **)(&input), &format);
	write(1, format.buffer, ft_strlen(format.buffer));
	va_end(format.args);
	free(format.buffer);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	// char	*c = "aiueo";
	// ft_printf("str: %s, addr: %p", c, c);
	// 浮動小数点数の桁数
	int num = 123456;
	char *str = "123456";
	ft_printf("aiueo%15s\n", str);
	printf("aiueo%15s\n", str);
	ft_printf("aiueo%100d\n", num);
	printf("aiueo%100d\n", num);
}
