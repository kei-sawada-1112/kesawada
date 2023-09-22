/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:32:48 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/21 19:50:25 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"
#include <stdio.h>

static int	is_in_set(char const s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		flag;
	char	*tmp;

	count = 0;
	flag = 1;
	tmp = (char *)s;
	while (*s)
	{
		if (flag && !is_in_set(*s, c))
		{
			count++;
			flag = 0;
		}
		else if (is_in_set(*s, c))
			flag = 1;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*start;
	char	*end;
	size_t	count;
	size_t	i;

	count = count_words(s, c);
	ret = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ret)
	{
		errno = ENOMEM;
		return (NULL);
	}
	start = (char *)s;
	end = ft_strchr(s, c);
	i = 0;
	while (i < count)
	{
		while (*start == c)
			start++;
		end = ft_strchr(start, c);
		if (!end)
			end = start + ft_strlen(start);
		ret[i] = ft_substr(start, 0, end - start);
		if (!ret[i])
		{
			while (i-- > 0)
			{
				free(ret[i]);
				return (NULL);
			}
		}
		start = end + 1;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
