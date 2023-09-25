/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:34:03 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/25 20:34:10 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *str1, const char *str2, size_t count)
{
	unsigned char	*ustr1;
	unsigned char	*ustr2;

	ustr1 = (unsigned char *)str1;
	ustr2 = (unsigned char *)str2;
	while (count--)
	{
		if (!*ustr1 && !*ustr2)
			return (0);
		if (*ustr1 != *ustr2)
			return ((int)(*ustr1 - *ustr2));
		ustr1++;
		ustr2++;
	}
	return (0);
}
