/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:33:04 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/20 17:33:59 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *str, const char c)
{
	char	*last;

	last = NULL;
	while (*str)
	{
		if (*str == c)
			last = (char *)str;
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (last);
}
