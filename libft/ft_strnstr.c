/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:38:31 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/21 16:13:35 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t count)
{
	size_t	nee_len;

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
