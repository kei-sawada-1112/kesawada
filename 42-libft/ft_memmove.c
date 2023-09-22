/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:27:32 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/20 17:28:09 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*udst;
	unsigned char	*usrc;

	udst = (unsigned char *)dest;
	usrc = (unsigned char *)src;
	if (usrc < udst && udst < usrc + count)
	{
		udst += count;
		usrc += count;
		while (count-- > 0)
			*(--udst) = *(--usrc);
	}
	else
	{
		while (count-- > 0)
			*udst++ = *usrc++;
	}
	return (dest);
}
