/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:25:01 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/12 22:07:41 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

size_t	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(const char *str)
{
	size_t	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, ft_strlen(str));
	return (len);
}

size_t	ft_putnbr(int num)
{
	char	c;
	size_t	len;

	len = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		if (num == INT_MIN)
		{
			write(1, "2147483648", 10);
			return (len += 11);
		}
		num = -num;
		len++;
	}
	if (num >= 10)
		len += ft_putnbr(num / 10);
	c = '0' + (num % 10);
	write(1, &c, 1);
	len += 1;
	return (len);
}

size_t	ft_putunbr(unsigned int unum)
{
	char	c;
	size_t	len;

	len = 0;
	if (unum >= 10)
		len += ft_putnbr(unum / 10);
	c = '0' + (unum % 10);
	write (1, &c, 1);
	len += 1;
	return (len);
}
