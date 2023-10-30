/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:38:31 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/09 19:42:06 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nee_len;

	if (!*needle)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	nee_len = ft_strlen(needle);
	while (*haystack && len >= nee_len)
	{
		if (*haystack == *needle
			&& (ft_strncmp(haystack, needle, nee_len) == 0))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
