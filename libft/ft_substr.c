/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:40:06 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/24 18:05:34 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	count;
	size_t	i;

	if (start >= ft_strlen(s) || len == 0)
	{
		ret = malloc(1);
		if (ret)
			ret[0] = '\0';
		return (ret);
	}
	count = len - (size_t)start + 1;
	if (count >= ft_strlen(s))
	{
		ret = ft_strdup(s);
		return (ret);
	}
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < len)
		ret[i] = s[start + i];
	ret[i] = '\0';
	return (ret);
}
