/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:35:29 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/27 10:35:17 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ret = malloc(1);
		ret[0] = '\0';
		return (ret);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
