/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:13:10 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/21 19:17:41 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

long    ft_strtol(const char *str, char *base)
{
	long    num;
	long    lim;
	int     sign;
    size_t  len;

    len = ft_strlen(base);
	num = 0;
	lim = LONG_MAX / len;
	sign = 1;
	str = check_space_and_sign(str, &sign);
	while (*str >= '0' && *str <= '9')
	{
		if (sign == 1)
		{
			if (num > lim || (num == lim && *str - '0' > LONG_MAX % len))
				return (LONG_MAX);
		}
		else
		{
			if (num > lim || (num == lim && *str - '0' > (LONG_MIN % len) * -1))
				return (LONG_MIN);
		}
		num = num * len + (*str - '0');
		str++;
	}
	return (num * sign);
}
