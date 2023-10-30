/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:22:41 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/22 12:42:27 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int		digit;
	char	*str;

	str = alloc_str(n, &digit);
	if (!str)
		return (NULL);
	str[digit] = '\0';
	while (--digit >= 0)
	{
		str[digit] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
