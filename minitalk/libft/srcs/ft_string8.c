/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:24:33 by kei               #+#    #+#             */
/*   Updated: 2023/09/15 23:11:38 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrev(char *str)
{
	char	*tmp;
	size_t	i;
	size_t	len;

	tmp = ft_strdup(str);
	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		str[i] = tmp[len - i - 1];
		i++;
	}
	str[i] = '\0';
	free(tmp);
	return (str);
}

char	*ft_strset(char *str, int ch)
{
	char	*ret;

	ret = str;
	while (*str)
	{
		*str = ch;
		str++;
	}
	return (ret);
}

void	*ft_memrev(void *ptr, size_t n)
{
	unsigned char	*uptr;
	unsigned char	*tmp;
	size_t			i;

	uptr = (unsigned char *)ptr;
	tmp = (unsigned char *)malloc(n);
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, uptr, n);
	i = 0;
	while (i < n)
	{
		uptr[i] = tmp[n - i - 1];
		i++;
	}
	free(tmp);
	return (ptr);
}

int	ft_isgraph(int c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}
