/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:40:06 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/22 14:12:47 by kesawada         ###   ########.fr       */
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

	if (start >= ft_strlen(s))
	{
		ret = malloc(1);
		ret[0] = '\0';
		return (ret);
	}
	count = len - (size_t)start;
	if (count >= ft_strlen(s))
		return (char *)(s);
	ret = (char *)malloc(count + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < count)
	{
		ret[i] = s[start + i];
		i++;
	}
	return (ret);
}
