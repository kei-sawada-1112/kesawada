/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:51:44 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/22 14:09:19 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	count_digit(int n)
{
	int	digit;

	digit = 0;
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static int	check_n_set_sign(int n, int *sign)
{
	if (n == 0)
		return (0);
	else if (n > 0)
		*sign = 1;
	else 
		*sign = -1;
	return (1);
}

static char	*alloc_str(int *digit, long *ln, int sign)
{
	char	*ret;

	if (sign == 1)
	{
		ret = (char *)malloc(*digit + 1);
		if (!ret)
			return (NULL);
	}
	else
	{
		ret = (char *)malloc(*digit + 2);
		if (!ret)
			return (NULL);
		ret[0] = '-';
		*ln *= -1;
		*digit += 1;
	}
	ret[*digit + 1] = '\0';
	(*digit)--;
	return (ret);
}

char	*ft_itoa(int n)
{
	int		digit;
	int		sign;
	char	*str;
	long	ln;

	digit = count_digit(n);
	if (!check_n_set_sign(n, &sign))
	{
		str = malloc(1);
		str[0] = '0';
		return (str);
	}
	ln = (long)n;
	str = alloc_str(&digit, &ln, sign);
	if (!str)
		return (NULL);
	while (digit >= 0)
	{
		str[digit] = ln % 10 + '0';
		ln /= 10;
		digit--;
		if (digit == 0 && sign == -1)
			break;
	}
	return (str);
}
