/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:51:36 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/26 16:32:28 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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
