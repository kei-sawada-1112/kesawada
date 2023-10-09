/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:35:29 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/09 19:41:25 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_recursively(long long num, int fd)
{
	char	c;

	if (num == 0)
		return ;
	print_recursively(num / 10, fd);
	c = num % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	ln;

	ln = (long long)n;
	if (ln == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln *= -1;
	}
	print_recursively(ln, fd);
}
