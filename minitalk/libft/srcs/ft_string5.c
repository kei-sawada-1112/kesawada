/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:27:21 by kei               #+#    #+#             */
/*   Updated: 2023/09/14 21:37:42 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	size_dst;
	size_t	size_src;
	size_t	i;

	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size_dst >= n)
		return (size_src + n);
	i = size_dst;
	while (*src && i < n - 1)
	{
		dst[i] = *src++;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (size_src + size_dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	size_src;
	size_t	i;

	size_src = ft_strlen(src);
	if (n == 0)
		return (size_src);
	i = 0;
	while (src[i] && i < n - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size_src);
}

char	*ft_strtok(const char *str, const char *delim)
{
	static char	*static_str;
	char		*token;

	if (str || !static_str)
		static_str = (char *)str;
	if (!static_str)
		return (NULL);
	while (*static_str && ft_strchr(delim, *static_str))
		static_str++;
	token = static_str;
	while (*static_str && !ft_strchr(delim, *static_str))
		static_str++;
	if (*static_str)
	{
		*static_str = '\0';
		static_str++;
	}
	if (token == static_str)
		return (NULL);
	return (token);
}

char	*ft_strpbrk(const char *str, const char *set)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

size_t	ft_strspn(const char *str, const char *accept)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (accept[j])
		{
			if (str[i] == accept[j])
				break ;
			j++;
		}
		if (!accept[j])
			return (i);
		i++;
	}
	return (i);
}
