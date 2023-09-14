/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:43:14 by kei               #+#    #+#             */
/*   Updated: 2023/09/14 14:42:31 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

char	*ft_strstr(char *haystack, const char *needle)
{
	char		*hay;
	const char	*nee;

	if (!*needle)
		return (haystack);
	while (*haystack)
	{
		hay = haystack;
		nee = needle;
		while (*hay && *nee && *hay == *nee)
		{
			hay++;
			nee++;
		}
		if (!*nee)
			return (haystack);
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

// const char* で引数をわたし、char * で返す場合内部で必ず malloc している。呼び出し元でfreeを 忘れないこと！！
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
