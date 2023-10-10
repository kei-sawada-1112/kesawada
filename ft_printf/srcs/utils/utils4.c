/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:22:41 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/10 17:33:50 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (n--)
	{
		if (!*us1 || !*us2 || *us1 != *us2)
			return ((int)(*us1 - *us2));
		us1++;
		us2++;
	}
	return (0);
}

static int	count_digit(unsigned int n)
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

static char	*alloc_str(unsigned int n, int *digit)
{
	char	*ret;

	*digit = count_digit(n);
	ret = (char *)malloc(*digit + 1);
	return (ret);
}

char	*ft_uitoa(unsigned int n)
{
	int			digit;
	char		*str;
	long long	ln;

	str = alloc_str(n, &digit);
	if (!str)
		return (NULL);
	str[digit] = '\0';
	ln = (long long)n;
	while (--digit >= 0)
	{
		str[digit] = ln % 10 + '0';
		ln /= 10;
	}
	return (str);
}
