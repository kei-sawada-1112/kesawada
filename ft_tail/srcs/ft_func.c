/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:44:35 by kei               #+#    #+#             */
/*   Updated: 2023/09/12 17:33:49 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}

char	*ft_strchr(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*ustr1;
	unsigned char	*ustr2;

	ustr1 = (unsigned char *)str1;
	ustr2 = (unsigned char *)str2;
	while (*ustr1 && *ustr2)
	{
		if (*ustr1 == *ustr2)
		{
			ustr1++;
			ustr2++;
		}
		else
			return (*ustr1 - *ustr2);
	}
	return (*ustr1 - *ustr2);
}

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	unsigned char	*ustr1;
	unsigned char	*ustr2;
	size_t			i;

	i = 0;
	ustr1 = (unsigned char *)str1;
	ustr2 = (unsigned char *)str2;
	while (*ustr1 && *ustr2 && i < num)
	{
		if (*ustr1 == *ustr2)
		{
			ustr1++;
			ustr2++;
		}
		else
			return (*ustr1 - *ustr2);
	}
	return (*ustr1 - *ustr2);
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
