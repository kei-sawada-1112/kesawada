/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:04:25 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/19 23:17:37 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_char(unsigned char c, unsigned char *buffer)
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

char	*convert_to_hexaddr(void *ptr, int dot_flag)
{
	char			*ret;
	unsigned char	*hex_addr;
	unsigned char	buffer[2];
	int				i;

	i = sizeof(ptr);
	hex_addr = malloc(sizeof(ptr) * 2 + 1);
	if (!hex_addr)
		return (NULL);
	hex_addr[sizeof(ptr) * 2] = '\0';
	while (--i >= 0)
	{
		hex_char((uintptr_t)ptr >> (i * 8) & 0xFF, buffer);
		hex_addr[2 * (sizeof(ptr) - 1 - i)] = buffer[0];
		hex_addr[2 * (sizeof(ptr) - 1 - i) + 1] = buffer[1];
	}
	i = 0;
	while (hex_addr[i] == '0')
		i++;
	if (*(hex_addr + i) == '\0' && !dot_flag)
		ret = ft_strdup("0");
	else
		ret = ft_strdup((char *)(hex_addr + i));
	free(hex_addr);
	return ((char *)(ret));
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
