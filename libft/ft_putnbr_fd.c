/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:35:29 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/25 18:35:31 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

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

static int	exponent(int num, int digits)
{
	if (num == 0 || digits < 1)
		return (0);
	if (num == 1)
		return (1);
	if (digits == 1)
	{
		return (num);
	}
	else
		return (num * exponent(num, digits - 1));
}

void	ft_putnbr_fd(int n, int fd)
{
	int			digit;
	char		c;
	long long	ln;
	int			i;

	digit = count_digit(n);
	ln = (long long)n;
	if (n == 0)
		write(fd, "0", 1);
	else if (ln < 0)
	{
		write(fd, "-", 1);
		ln *= -1;
	}
	i = 0;
	while (i < digit)
	{
		if (i == digit - 1)
			c = ln % 10 + '0';
		else
			c = ln / exponent(10, digit - i - 1) % 10 + '0';
		i++;
		write (fd, &c, 1);
	}
}
