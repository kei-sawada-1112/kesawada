/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:34:43 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/25 20:34:48 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static int	is_set_char(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	get_first(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (is_set_char(s1[i], set))
		i++;
	return (i);
}

static int	get_last(const char *s1, const char *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i >= 0 && is_set_char(s1[i], set))
		i--;
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		len;

	if (!s1 || !set)
		return (NULL);
	if (*set == '\0')
	{
		ret = ft_strdup(s1);
		return (ret);
	}
	len = get_last(s1, set) - get_first(s1, set);
	if (len <= 0)
	{
		ret = (char *)malloc(1);
		if (ret)
			*ret = '\0';
		return (ret);
	}
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1 + get_first(s1, set), len + 1);
	ret[len] = '\0';
	return (ret);
}
