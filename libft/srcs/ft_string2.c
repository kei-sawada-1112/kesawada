/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:43:41 by kei               #+#    #+#             */
/*   Updated: 2023/09/14 12:39:44 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*ustr1;
	unsigned char	*ustr2;

	ustr1 = (unsigned char *)str1;
	ustr2 = (unsigned char *)str2;
	while (*ustr1 || *ustr2)
	{
		if (*ustr1 != *ustr2)
			return (*ustr1 - *ustr2);
		ustr1++;
		ustr2++;
	}
	return (0);
}

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	unsigned char	*ustr1;
	unsigned char	*ustr2;
	size_t			i;

	i = 0;
	ustr1 = (unsigned char *)str1;
	ustr2 = (unsigned char *)str2;
	while ((*ustr1 || *ustr2) && i < num)
	{
		if (*ustr1 != *ustr2)
			return (*ustr1 - *ustr2);
		ustr1++;
		ustr2++;
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc(ft_strlen((char *)s) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc(n + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;

	ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	ft_strcpy(ret, s1);
	ft_strcat(ret, s2);
	return (ret);
}
