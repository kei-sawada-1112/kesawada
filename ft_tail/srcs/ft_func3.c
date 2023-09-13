/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:28:56 by kei               #+#    #+#             */
/*   Updated: 2023/09/13 16:30:15 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_tail.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] && haystack[i + j] == needle[j] && haystack[i + j])
				j++;
			if (!needle[j])
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

int ft_count_str(char *str, char *delimiter)
{
    int		count;
    char	*next;

	count = 0;
	next = ft_strstr(str, delimiter);
	while (next && *str)
	{
    	count++;
    	str = next + ft_strlen(delimiter);
    	next = ft_strstr(str, delimiter);
	}
	return (count + 1);
}

static char	*alloc_token(char *start, char *end)
{
	char *result;

	if (end)
		result = ft_strndup(start, end - start);
	else
		result = ft_strdup(start);
	return (result);
}

char **ft_split(char *str, char *delimiter)
{
	char	**result;
	char	*next;
	int		i;

	result = (char **)malloc(sizeof(char *) * (ft_count_str(str, delimiter) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*str)
	{
		next = ft_strstr(str, delimiter);
		result[i] = alloc_token(str, next);
		if (!result[i])
		{
			free_memory((void **)result, i - 1);
			return (NULL);
		}
		if (!next)
			break;
		str = next + ft_strlen(delimiter);
		i++;
	}
	result[i] = NULL;
	return (result);
}

size_t	ft_count_elements(char **array)
{
	int	count;

	count = 0;
	while (*array)
	{
		array++;
		count++;
	}
	return (count);
}
