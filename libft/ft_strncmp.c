/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:34:18 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/24 12:55:07 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strncmp(const char *str1, const char *str2, size_t count)
{
	unsigned char	*ustr1;
	unsigned char	*ustr2;

	ustr1 = (unsigned char *)str1;
	ustr2 = (unsigned char *)str2;
	while (count--)
	{
		if (*ustr1 != *ustr2)
			return ((int)(*ustr1 - *ustr2));
		ustr1++;
		ustr2++;
	}
	return (0);
}
