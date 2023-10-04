/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:27:32 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/30 12:12:22 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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
