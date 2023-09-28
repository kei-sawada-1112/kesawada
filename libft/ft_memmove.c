/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:27:32 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/28 10:54:19 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*udst;
	unsigned char	*usrc;

	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (usrc < udst && udst < usrc + len)
	{
		udst += len;
		usrc += len;
		while (len-- > 0)
			*(--udst) = *(--usrc);
	}
	else
	{
		while (len-- > 0)
			*udst++ = *usrc++;
	}
	return (dst);
}
