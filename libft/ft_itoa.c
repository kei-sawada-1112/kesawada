/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:31:11 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/27 11:18:40 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

static int	check_n_set_sign(int n)
{
	int	sign;

	if (n >= 0)
		sign = 1;
	else
		sign = -1;
	return (sign);
}

static char	*alloc_str(int *digit, long long *ln, int sign)
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
	ret[*digit] = '\0';
	(*digit)--;
	return (ret);
}

char	*str_zero(void)
{
	char	*ret;

	ret = (char *)malloc(2);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

char	*ft_itoa(int n)
{
	int			digit;
	int			sign;
	char		*str;
	long long	ln;

	digit = count_digit(n);
	sign = check_n_set_sign(n);
	ln = (long long)n;
	if (n == 0)
	{
		str = str_zero();
		return (str);
	}
	str = alloc_str(&digit, &ln, sign);
	if (!str)
		return (NULL);
	while (digit >= 0)
	{
		str[digit] = ln % 10 + '0';
		ln /= 10;
		digit--;
		if (digit == 0 && sign == -1)
			break ;
	}
	return (str);
}
