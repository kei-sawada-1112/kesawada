/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:31:11 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/21 13:45:25 by kesawada         ###   ########.fr       */
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

char	*ft_itoa(int n)
{
	int		digit;
	char	*str;

	digit = count_digit(n);
	str = (char *)malloc(digit + 1);
	if (!str)
		return (NULL);
	str[digit] = '\0';
	while (digit > 0)
	{
		str[digit - 1] = n % 10 + '0';
		n /= 10;
		digit--;
	}
	return (str);
}
