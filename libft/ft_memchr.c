/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:36:17 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/21 12:28:02 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t count)
{
	unsigned char	*us;
	unsigned char	uc;

	us = (unsigned char *)s;
	uc = (unsigned char)c;
	while (count-- > 0)
	{
		if (*us == uc)
			return ((void *)us);
		us++;
	}
	return (NULL);
}
