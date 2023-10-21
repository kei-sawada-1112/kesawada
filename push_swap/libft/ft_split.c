/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:35:59 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/09 19:41:32 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static char	**create_ret(char const *s, int count, char c)
{
	char	**ret;
	int		i;

	ret = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < count)
	{
		ret[i] = create_substr((char **)&s, c);
		if (!ret[i])
		{
			while (--i)
				free(ret[i]);
			free(ret);
			return (NULL);
		}
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	int		count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	return (create_ret(s, count, c));
}
