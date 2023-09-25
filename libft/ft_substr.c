/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:35:29 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/25 20:36:15 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static int	check_diff(char const *s, unsigned int start, size_t len)
{
	int	diff;

	diff = start - len;
	if (diff < 0)
		diff *= -1;
	if (diff > (int)ft_strlen(s))
		len = ft_strlen(s) - start;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (start >= ft_strlen(s) || len == 0)
	{
		ret = malloc(1);
		ret[0] = '\0';
		return (ret);
	}
	len = check_diff(s, start, len);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	i = 0;
	while (i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
