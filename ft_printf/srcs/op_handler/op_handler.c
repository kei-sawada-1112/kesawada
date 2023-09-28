/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:22:06 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/28 18:14:24 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include <stdarg.h>

#include <stdio.h>

void	handle_c(va_list args)
{
	char	value;

	value = (char) va_arg(args, int);
	write(1, &value, 1);
}

void	handle_s(va_list args)
{
	char	*value;

	value = (char *) va_arg(args, char *);
	write(1, value, ft_strlen(value));
}

void	handle_p(va_list args)
{
	char	*value;

	value = (char *) va_arg(args, char *);
	print_hex_addr(value);
}

void	handle_d(va_list args)
{
	int	value;

	value = va_arg(args, int);
	printf("value: %d\n", value);
}

void	handle_i(va_list args)
{
	int	value;

	value = va_arg(args, int);
	printf("value: %d\n", value);
}

