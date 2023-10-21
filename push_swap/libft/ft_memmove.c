/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:27:32 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/09 19:41:05 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*udst;
	unsigned char	*usrc;

	if (!dst && !src)
		return (NULL);
	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	if (usrc < udst && udst < usrc + len)
	{
		udst += len;
		usrc += len;
		while (len--)
			*(--udst) = *(--usrc);
	}
	else
	{
		while (len--)
			*udst++ = *usrc++;
	}
	return (dst);
}
