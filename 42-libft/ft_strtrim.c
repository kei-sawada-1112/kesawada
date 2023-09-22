/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:50:46 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/21 20:52:00 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static char	*get_first(const char *s1, const char *set)
{
	char	*tmp_set;
	int		flag;

	tmp_set = (char *)set;
	flag = 0;
	while (*s1)
	{
		while (*set)
		{
			if (*s1 == *set)
			{
				s1++;
				set = tmp_set;
				flag = 1;
			}
			else
				set++;
		}
		if (flag)
			return ((char *)s1);
		set = tmp_set;
		s1++;
	}
	return ((char *)s1);
}

static char	*get_last(const char *s1, const char *set)
{
	char	*tmp_set;
	int		flag;

	tmp_set = (char *)set;
	flag = 0;
	s1 += (ft_strlen(s1) - 1);
	while (*s1)
	{
		while (*set)
		{
			if (*s1 == *set)
			{
				s1--;
				set = tmp_set;
				flag = 1;
			}
			else
				set++;
		}
		if (flag)
			return ((char *)s1 + 1);
		set = tmp_set;
		s1--;
	}
	return ((char *)s1 + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	*first;
	char	*last;
	char	*tmp;
	int		len;
	
	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0' || *set == '\0')
		return ((char *)s1);
	first = get_first(s1, set);
	//last = get_last(first, set);
	last = get_last(s1, set);
	printf("first: %s\n", first);
	printf("last:  %s\n", last);
	// if (ft_strlen(first) < ft_strlen(last) && *first != '\0')
	// 	return (first);
	// else if (ft_strlen(first) > ft_strlen(last) && *first != '\0')
	// 	return (last);
	// else if (ft_strlen(s1) == ft_strlen(last))
	// 	return (first);
	// else if (*first == '\0')
	// 	return (last);
	len = first - last;
	if (len > 0)
		tmp = first;
	else
		tmp = last;
	ret = (char *)malloc(ft_strlen(tmp));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, tmp, ft_strlen(tmp));
	return (ret);
}
