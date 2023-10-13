/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:04:29 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/13 09:38:14 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	write_args(const char *input, va_list args)
{
	if (*input == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*input == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*input == 'd' || *input == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (*input == 'p')
		return (ft_putaddress(va_arg(args, void *)));
	else if (*input == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (*input == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (*input == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (*input == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(*input));
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	size_t	count;

	count = 0;
	va_start(args, input);
	while (*input)
	{
		if (*input == '%')
		{
			if (!*(input + 1))
				return (count);
			input++;
			count += write_args(input, args);
		}
		else
		{
			count++;
			ft_putchar(*input);
		}
		input++;
	}
	va_end(args);
	return (count);
}
