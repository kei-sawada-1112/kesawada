/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:18:16 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/15 17:19:24 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s1)
{
	size_t	count;

	count = 0;
	while (s1[count])
		count++;
	return (count);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dup;
	size_t	i;
	size_t	size;

	size = ft_strlen(s1);
	if (size > n)
		size = n;
	dup = (char *)malloc(size + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*ret;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = malloc(len1 + len2 + 1);
	i = 0;
	j = 0;
	while (i < len1)
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < len2 + len1)
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}

size_t	next_line_len(t_list *list)
{
	size_t	count;

	count = 0;
	while (list->str[count])
	{
		if (!list->str[count])
			break;
		if (list->str[count] == '\n')
			break ;
		count++;
	}
	return (count);
}

char	*find_next_line(t_list *list)
{
	size_t	count;
	char	*next_line;
	char	*tmp_str;
	size_t	i;

	count = next_line_len(list);

	next_line = malloc(count + 1);
	tmp_str = ft_strndup(list->str + count + 1, ft_strlen(list->str) - count);
	i = 0;
	while (i < count + 1)
	{
		next_line[i] = list->str[i];
		i++;
	}
	next_line[i] = '\0';
	free(list->str);
	list->str = tmp_str;
	return (next_line);
}
