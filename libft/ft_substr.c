/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:35:29 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/26 19:20:16 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

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
