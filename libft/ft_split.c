/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:32:48 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/25 12:47:36 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(const char *str, char c)
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

	first = *pstr;
	while (**pstr && **pstr != c)
		(*pstr)++;
	last = *pstr;
	while (**pstr && **pstr == c)
		(*pstr)++;
	return (ft_substr(first, 0, last - first));
}

static char	**alloc_memory(char *trimmed_str, int words)
{
	char **ret;

	ret  = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ret)
	{
		free(trimmed_str);
		return (NULL);
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*trimmed_str;
	int		words;
	int		i;
	char	set[2];

	if (!s)
		return (NULL);
	set[0] = c;
	set[1] = '\0';
	trimmed_str = ft_strtrim(s, set);
	if (!trimmed_str)
		return (NULL);
	words = count_words(trimmed_str, c);
	ret = alloc_memory(trimmed_str, words);
	i = 0;
	s = trimmed_str;
	while (i < words)
		ret[i++] = create_substr((char **)&s, c);
	ret[i] = NULL;
	free(trimmed_str);
	return (ret);
}
