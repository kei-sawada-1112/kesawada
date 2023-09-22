/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:51:36 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/20 17:52:16 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t count)
{
	unsigned char	uc;
	unsigned char	*us;

	uc = (unsigned char)c;
	us = (unsigned char *)s;
	while (count-- > 0)
		*us++ = uc;
	return (s);
}
