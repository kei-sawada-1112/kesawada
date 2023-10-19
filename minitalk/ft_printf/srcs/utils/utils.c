/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:18:11 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/10 17:19:49 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*check_space_and_sign(const char *nptr, int *sign)
{
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		*sign = -1;
		nptr++;
	}
	return (nptr);
}

int	ft_atoi(const char *str)
{
	long long	num;
	long long	lim;
	int			sign;

	num = 0;
	lim = LONG_MAX / 10;
	sign = 1;
	str = check_space_and_sign(str, &sign);
	while (*str >= '0' && *str <= '9')
	{
		if (sign == 1)
		{
			if (num > lim || (num == lim && *str - '0' > LONG_MAX % 10))
				return ((int)LONG_MAX);
		}
		else
		{
			if (num > lim || (num == lim && *str - '0' > (LONG_MIN % 10) * -1))
				return ((int)LONG_MIN);
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	return ((int)(num * sign));
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ustr;
	size_t			i;

	ustr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ustr[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	num;

	num = 1;
	if (!size || !count)
		return (ft_calloc(1, 1));
	if (size > SIZE_MAX / count)
		return (NULL);
	num = size * count;
	if (num == SIZE_MAX)
		return (NULL);
	ret = (char *)malloc(num);
	if (!ret)
		return (NULL);
	ft_bzero(ret, num);
	return (ret);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
