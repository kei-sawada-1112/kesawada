/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:27:01 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/21 20:50:59 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

void	*ft_memcpy(void *dst, const void *src, size_t count)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (count--)
		*d++ = *s++;
	return (dst);
}
