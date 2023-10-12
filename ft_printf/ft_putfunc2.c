/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfunc2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:25:01 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/12 22:14:02 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_base(unsigned int num, char *base)
{
	char		c;
	size_t		base_len;
	size_t		len;

	len = 0;
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	if (num >= (unsigned int)base_len)
		len += ft_putnbr_base(num / base_len, base);
	c = base[num % (int)base_len];
	write(1, &c, 1);
	len += 1;
	return (len);
}

size_t	ft_putaddress(void *ptr)
{
	int					i;
	char				buffer[16];
	unsigned long long	addr;
	size_t				len;

	if (!ptr)
	{
		ft_putstr("0x0");
		return (3);
	}
	i = 14;
	buffer[15] = '\0';
	addr = (unsigned long long) ptr;
	while (addr)
	{
		if (addr % 16 >= 10)
			buffer[i] = addr % 16 - 10 + 'a';
		else
			buffer[i] = addr % 16 + '0';
		addr /= 16;
		i--;
	}
	write(1, "0x", 2);
	len = 16 - i;
	ft_putstr(&buffer[i + 1]);
	return (len);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char *str ="aiueo";
// 	ft_putaddress(str);
// 	printf("%p", str);
// }
