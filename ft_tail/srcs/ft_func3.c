/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:28:56 by kei               #+#    #+#             */
/*   Updated: 2023/09/12 18:38:19 by kei              ###   ########.fr       */
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

char **ft_split(char *str, char *delimiter)
{
	char	**result;
	char	*next;
	int		i;
	int		count;

	count = ft_count_str(str, delimiter);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	next = ft_strstr(str, delimiter);
	i = 0;
	while (next && *str)
	{
        result[i] = (char *)malloc(next - str + 1);
        if (!result[i])
        {
			while (i > 0)
				free(result[i--]);
			free(result);
			return (NULL);
		}
		ft_memcpy(result[i], str, next - str);
		result[i][next - str] = '\0';
		str = next + ft_strlen(delimiter);
		next = ft_strstr(str, delimiter);
        i++;
    }
    if (*str)
        result[i] = ft_strdup(str);
	else
		result[i] = NULL;
    result[i + 1] = NULL;
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
