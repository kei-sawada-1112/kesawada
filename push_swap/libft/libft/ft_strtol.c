/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:48:25 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/06 15:28:24 by kesawada         ###   ########.fr       */
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

long	ft_strtol(const char *str, int base)
{
	long long	num;
	long long	lim;
	int			sign;

	num = 0;
	lim = LONG_MAX / 10;
	sign = 1;
	str = check_space_and_sign(str, &sign);
	if (*str == '\0')
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (*str >= '0' && *str <= '9')
	{
		if (sign == 1)
		{
			if (num > lim || (num == lim && *str - '0' > LONG_MAX % base))
				return ((int)LONG_MAX);
		}
		else
		{
			if (num > lim || (num == lim && *str - '0' > (LONG_MIN % base) * -1))
				return ((int)LONG_MIN);
		}
		num = num * base + (*str - '0');
		str++;
	}
	return (num * sign);
}
