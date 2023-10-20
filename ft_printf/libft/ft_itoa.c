/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:31:11 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/09 19:40:38 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
