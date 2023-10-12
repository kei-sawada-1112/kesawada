/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:04:29 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/12 13:18:32 by kesawada         ###   ########.fr       */
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
	format->f_sharp = 0;
	format->f_minus = 0;
	format->f_plus = 0;
	format->f_space = 0;
	format->f_zero = 0;
	format->f_dot = 0;
	format->f_num = 0;
	format->f_asta = 0;
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

// int	main(void)
// {
// 	// スペース+数値のパターンがテストにない
// 	// %012s　みたいのもない?
// 	// それぞれの変数にNULL入れるパターン
// 	// 16以上でバグる
// 	// void *str = 0x1903150;
// 	ft_printf("%90.%");
// 	printf("\n");
// 	printf("%90.%");
// 	// ft_printf(" %1c %2c %3c\n", '0', 0, '1');
// 	// ft_printf(" %-1c %-2c %-3c\n", '0', 0, '1');
// 	// printf(" %1c %2c %3c\n", '0', 0, '1');
// 	// printf(" %-1c %-2c %-3c\n", '0', 0, '1');
// 	// ft_printf(" %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	// printf(" %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

// 	// ft_printf(" %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	// printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	// char	*c = "aiueo";
// 	// ft_printf("str: %s, addr: %p", c, c);
// 	// unsigned int num = 123456;
// 	// int num = INT_MAX;
// 	// char *str = "12345";
// 	// ft_printf("aiueo%%sa\n");
// 	// printf("aiueo%%sa\n");
// 	// i = ft_printf("aiueo%ca\n", 0);
// 	// ft_printf("p: %p\n", 0);
// 	// printf("p: %p\n", 0);
// 	// i = printf("aiueo%ca\n", 0);
// 	// ft_printf("i: %d\n", i);
// 	// printf("aiueo%ca\n", 0);

// 	// ft_printf("aiueo%p\n", str);
// 	// printf("aiueo%p\n", str);

// // 	// ft_printf("aaa%#15Xbbb\n", num);
// // 	// printf("aaa%#15Xbbb\n", num);

// // 	// ft_printf("aaa%100dbbb\n", num);
// // 	// printf("aaa%100dbbb\n", num);

// 	//system("leaks a.out");
// }
