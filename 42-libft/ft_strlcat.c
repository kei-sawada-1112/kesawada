/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:31:01 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/21 15:46:45 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst;
	size_t	size_src;
	size_t	i;

	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size_dst >= size)
		return (size_src + size);
	i = size_dst;
	while (*src && i < size - 1)
	{
		dst[i] = *src++;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (size_src + size_dst);
}
