/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:54:59 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/09 19:41:08 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	uc;
	unsigned char	*us;

	uc = (unsigned char)c;
	us = (unsigned char *)s;
	while (len--)
		*us++ = uc;
	return (s);
}
