/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:43:14 by kei               #+#    #+#             */
/*   Updated: 2023/09/14 12:44:35 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*hay;
	const char	*nee;

	if (!*needle)
		return ((char *)haystack);
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
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
