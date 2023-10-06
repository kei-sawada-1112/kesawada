/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:45:33 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/06 20:40:33 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>
#include <limits.h>

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
	format->precision = 0;
	format->prefix = 0;
	format->type = 0;
	format->width = 0;
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

// int	main(void)
// {
// 	// char	*c = "aiueo";
// 	// ft_printf("str: %s, addr: %p", c, c);
// //	unsigned int num = 123456;
// 	// int num = INT_MAX;
// 	// char *str = "12345";
// 	// ft_printf("aiueo%%sa\n");
// 	// printf("aiueo%%sa\n");
// //int	i;
// 	//i = ft_printf("aiueo%ca\n", 0);
// 	ft_printf("aiueo%saaaa\n", "");
// 	// i = printf("aiueo%ca\n", 0);
// 	// ft_printf("i: %d\n", i);
// 	//printf("aiueo%ca\n", 0);

// 	// ft_printf("aiueo%p\n", str);
// 	// printf("aiueo%p\n", str);

// 	// ft_printf("aaa%#15Xbbb\n", num);
// 	// printf("aaa%#15Xbbb\n", num);

// 	// ft_printf("aaa%100dbbb\n", num);
// 	// printf("aaa%100dbbb\n", num);

// 	//system("leaks a.out");
// }
