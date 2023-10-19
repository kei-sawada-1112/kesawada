/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:31:01 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/09 19:41:50 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst;
	size_t	size_src;
	size_t	i;

	size_src = ft_strlen(src);
	if (!size)
		return (size_src);
	size_dst = ft_strlen(dst);
	if (size_dst >= size)
		return (size_src + size);
	dst += size_dst;
	i = 0;
	while (*src && i < size - size_dst - 1)
	{
		*(dst++) = *(src++);
		i++;
	}
	*dst = '\0';
	return (size_src + size_dst);
}
