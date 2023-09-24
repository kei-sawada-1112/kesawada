/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:32:48 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/24 12:50:01 by kei              ###   ########.fr       */
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

static char	*create_ret_entry(char **pstr, char c)
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

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*trimmed_str;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	trimmed_str = ft_strtrim(s, &c);
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
	while (i < words)
		ret[i++] = create_ret_entry((char **)&s, c);
	ret[i] = NULL;
	free(trimmed_str);
	return (ret);
}
