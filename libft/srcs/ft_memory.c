/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:54:15 by kei               #+#    #+#             */
/*   Updated: 2023/09/15 22:55:54 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*us;

	uc = (unsigned char)c;
	us = (unsigned char *)s;
	while (n-- > 0)
		*us++ = uc;
	return (s);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*us;
	unsigned char	uc;

	us = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n-- > 0)
	{
		if (*us == uc)
			return ((void *)us);
		us++;
	}
	return (NULL);
}

void	*ft_memrchr(const void *s, int c, size_t n)
{
	unsigned char	*us;
	unsigned char	uc;

	us = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n-- > 0)
	{
		if (us[n] == uc)
			return ((void *)&us[n]);
	}
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (size--)
		*d++ = *s++;
	return (dst);
}

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*udst;
	unsigned char	*usrc;

	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	while (n--)
	{
		*udst = *usrc;
		if (*usrc == (unsigned char)c)
			return (udst + 1);
		udst++;
		usrc++;
	}
	return (NULL);
}
