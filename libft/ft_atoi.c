/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:40:54 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/24 12:50:55 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include <stdio.h>

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
	long	num;
	long	lim;
	int		sign;

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
