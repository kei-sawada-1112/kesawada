/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:20:01 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/12 14:00:22 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	count_digit(int n)
{
	int	digit;

	if (n == 0)
		return (1);
	digit = 0;
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static char	*alloc_str(int n, int *digit)
{
	char	*ret;

	*digit = count_digit(n);
	if (n < 0)
		(*digit)++;
	ret = (char *)malloc(*digit + 1);
	return (ret);
}

char	*ft_itoa(int n)
{
	int			digit;
	int			sign;
	char		*str;
	long long	ln;

	if (n >= 0)
		sign = 1;
	else
		sign = -1;
	str = alloc_str(n, &digit);
	if (!str)
		return (NULL);
	str[digit] = '\0';
	ln = (long long)n * sign;
	while (--digit >= 0)
	{
		str[digit] = ln % 10 + '0';
		ln /= 10;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t count)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (count--)
		*d++ = *s++;
	return (dst);
}

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	uc;
	unsigned char	*us;

	uc = (unsigned char)c;
	us = (unsigned char *)s;
	while (len--)
		*us++ = uc;
	return (s);
}
