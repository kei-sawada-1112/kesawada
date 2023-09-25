/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:38:31 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/25 20:34:22 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t count)
{
	size_t	nee_len;

	if (!hay && !count)
		return (NULL);
	if (!*nee)
		return ((char *)hay);
	nee_len = ft_strlen(nee);
	while (*hay && count >= nee_len)
	{
		if (*hay == *nee && (ft_strncmp(hay, nee, nee_len) == 0))
			return ((char *)hay);
		hay++;
		count--;
	}
	return (NULL);
}
