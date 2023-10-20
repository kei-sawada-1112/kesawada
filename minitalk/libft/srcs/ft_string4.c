/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:37:22 by kei               #+#    #+#             */
/*   Updated: 2023/09/20 12:16:46 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	ft_numlen(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numlen(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	len = len - 1;
	while (len >= 0 && str[len] != '-')
	{
		str[len] = '0' + n % 10;
		n /= 10;
		len--;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	str = preprocess(str, &sign);
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

// int	atoi(const char *str)
// {
// 	long long	res;
// 	int			sign;

// 	res = 0;
// 	sign = 1;
// 	str = process_sign(str, &sign);
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		if (res > LONG_MAX / 10 || (res == LONG_MAX / 10 && *str
// 				- '0' > LONG_MAX % 10))
// 		{
// 			if (sign == 1)
// 				return ((int)LONG_MAX);
// 			return ((int)LONG_MIN);
// 		}
// 		res = res * 10 + (*str - '0');
// 		str++;
// 	}
// 	return ((int)sign * res);
// }

char	*ft_strrchr(const char *str, const char c)
{
	char	*last;

	last = NULL;
	while (*str)
	{
		if (*str == c)
			last = (char *)str;
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (last);
}

char	*ft_strnstr(const char *hay, const char *nee, size_t n)
{
	size_t	nee_len;

	if (!*nee)
		return ((char *)hay);
	nee_len = ft_strlen(nee);
	while (*hay && n >= nee_len)
	{
		if (*hay == *nee && !ft_strncmp(hay, nee, nee_len))
			return ((char *)hay);
		hay++;
		n--;
	}
	return (NULL);
}