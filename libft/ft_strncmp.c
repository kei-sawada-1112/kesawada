/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:34:03 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/28 11:33:11 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;

	if (!s1 && !s2)
		return (0);
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (n--)
	{
		if (!*us1 || !*us2 || *us1 != *us2)
			return ((int)(*us1 - *us2));
		us1++;
		us2++;
	}
	return (0);
}
