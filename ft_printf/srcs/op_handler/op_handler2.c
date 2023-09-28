/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handler2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:24:42 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/28 16:56:05 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include <stdarg.h>

#include <stdio.h>

void	handle_u(va_list args)
{
	double	value;

	value = va_arg(args, double);
	printf("value: %f\n", value);
}

void	handle_x(va_list args)
{
	double	value;

	value = va_arg(args, double);
	printf("value: %f\n", value);
}

void	handle_X(va_list args)
{
	double	value;

	value = va_arg(args, double);
	printf("value: %f\n", value);
}

void	handle_per(va_list args)
{
	va_arg(args, int);
	write (1, "%", 1);
}
