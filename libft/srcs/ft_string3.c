/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:43:14 by kei               #+#    #+#             */
/*   Updated: 2023/09/14 21:28:50 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	needle_len;

	if (!*needle)
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack)
	{
		if (*haystack == *needle && !ft_strncmp(haystack, needle, needle_len))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

char	*ft_strtrim(const char *str)
{
	char	*start;
	char	*end;
	char	*ret;
	char	*tmp;

	while (ft_isspace(*str))
		str++;
	start = (char *)str;
	end = start;
	while (*end)
		end++;
	end--;
	while (end >= start && ft_isspace(*end))
		end--;
	ret = (char *)malloc(end - start + 2);
	if (!ret)
		return (NULL);
	tmp = ret;
	while (start <= end)
		*tmp++ = *start++;
	*(tmp) = '\0';
	return (ret);
}

size_t	ft_count_words(char const *str)
{
	size_t	count;
	int		flag;

	count = 0;
	flag = 1;
	while (*str)
	{
		if (ft_isspace(*str))
			flag = 1;
		else if (flag)
		{
			count++;
			flag = 0;
		}
		str++;
	}
	return (count);
}
