/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:04:25 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/09 00:34:11 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

#include <stdio.h>

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

char	*convert_to_hexaddr(unsigned long ptr)
{
	char	*hex_addr;
	char	*ret;
	char	buffer[2];
	int		i;

	i = sizeof(ptr) - 1;
	hex_addr = malloc(sizeof(ptr) * 2 + 1);
	if (!hex_addr)
		return (ft_calloc(1, 1));
	hex_addr[sizeof(ptr) * 2] = '\0';
	while (i >= 0)
	{
		hex_char(ptr
			>> ((sizeof(ptr) + i) * 8) & 0xFF, buffer);
		hex_addr[2 * (sizeof(ptr) - 1 - i)] = buffer[0];
		hex_addr[2 * (sizeof(ptr) - 1 - i) + 1] = buffer[1];
		i--;
	}
	i = 0;
	while (hex_addr[i] == '0')
		i++;
	ret = ft_strjoin("0x", hex_addr + i);
	free(hex_addr);
	return (ret);
}

char	*recursive_convert(char *hex, unsigned int num, int *i, int type)
{
	char	c;

	if (num == 0)
		return (hex);
	c = num % 16;
	if (c < 10)
		c += '0';
	else
		c += (type == TYPE_X) * 'a' + (type == TYPE_LX) * 'A' - 10;
	recursive_convert(hex, num / 16, i, type);
	hex[*i] = c;
	(*i)++;
	return (hex);
}

char	*convert_to_hex(int num, int type)
{
	char	*hex;
	int		i;

	i = 0;
	if (num == 0)
	{
		hex = ft_calloc(2, 1);
		if (!hex)
			return (NULL);
		hex[0] = '0';
		return (hex);
	}
	hex = malloc(9);
	if (!hex)
		return (NULL);
	recursive_convert(hex, (unsigned int)num, &i, type);
	hex[i] = '\0';
	return (hex);
}
