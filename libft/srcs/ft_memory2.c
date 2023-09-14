/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:59:49 by kei               #+#    #+#             */
/*   Updated: 2023/09/14 18:23:13 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	ft_memcmp(const void *mem1, const void *mem2, size_t n)
{
	unsigned char	*u1;
	unsigned char	*u2;

	u1 = (unsigned char *)mem1;
	u2 = (unsigned char *)mem2;
	while (n--)
	{
		if (*u1 != *u2)
			return (*u1 - *u2);
		u1++;
		u2++;
	}
	return (0);
}

void	*ft_memalloc(size_t n)
{
	unsigned char	*mem;
	size_t			i;

	mem = (unsigned char *)malloc(n);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < n)
	{
		mem[i] = 0;
		i++;
	}
	return ((void *)mem);
}

void	ft_memdel(void **mem)
{
	free(mem);
	mem = NULL;
}
