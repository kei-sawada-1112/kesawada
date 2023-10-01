/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:45:33 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/01 16:33:20 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

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
	format->sign = 1;
}

int	ft_printf(const char *input, ...)
{
	t_format	format;
	size_t		total_len;

	va_start(format.args, input);
	init_buffer(&format);
	init_format(&format);
	while (*input)
		state_based_process((char **)(&input), &format);
	write(1, format.buffer, ft_strlen(format.buffer));
	va_end(format.args);
	total_len = ft_strlen(format.buffer);
	free(format.buffer);
	return (total_len);
}

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	// char	*c = "aiueo";
	// ft_printf("str: %s, addr: %p", c, c);
	// 浮動小数点数の桁数
//	unsigned int num = 123456;
	int num = 16;
	char *str = "12345";
	ft_printf("aiueo%%sa\n");
	printf("aiueo%%sa\n");

	ft_printf("aiueo%ca\n", 'a');
	printf("aiueo%ca\n", 'a');

	ft_printf("aiueo%15s\n", str);
	printf("aiueo%15s\n", str);

	ft_printf("aaa%xbbb\n", num);
	printf("aaa%xbbb\n", num);
}
