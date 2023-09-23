/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:32:48 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/23 18:26:38 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(const char *str, char c)
{
	int count = 0;
	int in_word = 0;

	while (*str)
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c && in_word)
		{
			in_word = 0;
		}
		str++;
	}
	return count;
}
static int	is_in_set(char const s, char c)
{
	return (s == c);
}

static char	*create_ret_entry(char **pstr, char c)
{
	char	*start;
	char	*end;

	start = *pstr;
	while (**pstr && !is_in_set(**pstr, c))
		(*pstr)++;
	end = *pstr;
	while (**pstr && is_in_set(**pstr, c))
		(*pstr)++;
	return (ft_substr(start, 0, end - start));
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*trimmed_str;
	int		words;
	int		i;

	if (!s)
		return (NULL);

	char set[2] = {c, '\0'};
	trimmed_str = ft_strtrim(s, set);
	if (!trimmed_str)
		return (NULL);
	words = count_words(trimmed_str, c);
	ret = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ret)
	{
		free(trimmed_str);
		return (NULL);
	}
	i = 0;
	s = trimmed_str;
	while (*s && i < words)
		ret[i++] = create_ret_entry((char **)&s, c);

	ret[i] = NULL;
	free(trimmed_str);
	return (ret);
}
