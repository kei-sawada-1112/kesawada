/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:04:25 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/28 18:12:03 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

void	hex_char(char c, char *buffer)
{
	size_t	i;

	buffer[0] = c >> 4 & 0x0F;
	buffer[1] = c & 0x0F;
	i = 0;
	while (i < 2)
	{
		if (buffer[i] >= 10)
			buffer[i] += 'a' - 10;
		else
			buffer[i] += '0';
		i++;
	}
}

void	print_hex_addr(char *ptr)
{
	char	hex_addr[sizeof(ptr) * 2];
	char	buffer[2];
	int		i;

	write(1, "0x", 2);
	i = sizeof(ptr) - 1;
	while (i >= 0)
	{
		hex_char((unsigned long long)ptr >> ((sizeof(ptr) + i) * 8) & 0xFF, buffer);
		hex_addr[2 * (7 - i)] = buffer[0];
		hex_addr[2 * (7 - i) + 1] = buffer[1];
		i--;
	}
	i = 0;
	while (hex_addr[i] == '0')
		i++;
	write(1, &hex_addr[i], 2 * sizeof(ptr) - i);
	write(1, "\n", 1);
}
