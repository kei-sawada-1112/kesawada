/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:38:31 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/26 15:06:28 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t count)
{
	size_t	nee_len;

	if (!*nee)
		return (char *)hay;
	if (count == 0)
		return (NULL);
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
