/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:35:59 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/27 10:57:57 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static int	count_words(char const *str, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && !flag)
		{
			flag = 1;
			count++;
		}
		else if (*str == c && flag)
			flag = 0;
		str++;
	}
	return (count);
}

static char	*create_substr(char **pstr, char c)
{
	char	*first;
	char	*last;

	while (**pstr && **pstr == c)
		(*pstr)++;
	first = *pstr;
	while (**pstr && **pstr != c)
		(*pstr)++;
	last = *pstr;
	return (ft_substr(first, 0, last - first));
}

static char	**alloc_memory(char *s, int words)
{
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ret)
	{
		free(s);
		return (NULL);
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		words;
	int		i;

	words = count_words(s, c);
	ret = alloc_memory((char *)s, words);
	i = 0;
	while (i < words)
	{
		ret[i] = create_substr((char **)&s, c);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
