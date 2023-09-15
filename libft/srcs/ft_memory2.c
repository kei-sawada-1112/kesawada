/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:59:49 by kei               #+#    #+#             */
/*   Updated: 2023/09/15 23:15:18 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*udst;
	unsigned char	*usrc;

	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	if (usrc < udst && udst < usrc + n)
	{
		udst += n;
		usrc += n;
		while (n-- > 0)
			*(--udst) = *(--usrc);
	}
	else
	{
		while (n-- > 0)
			*udst++ = *usrc++;
	}
	return (dst);
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

void	*ft_realloc(void *ptr, size_t orig_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (ptr && orig_size)
	{
		if (orig_size < new_size)
			ft_memcpy(new_ptr, ptr, orig_size);
		else
			ft_memcpy(new_ptr, ptr, new_size);
		free(ptr);
	}
	return (new_ptr);
}

void	ft_memdel(void **mem)
{
	free(mem);
	mem = NULL;
}
