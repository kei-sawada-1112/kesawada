/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:36:55 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/21 16:54:44 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *mem1, const void *mem2, size_t count)
{
	unsigned char	*u1;
	unsigned char	*u2;

	u1 = (unsigned char *)mem1;
	u2 = (unsigned char *)mem2;
	while (count--)
	{
		if (*u1 != *u2)
			return (*u1 - *u2);
		u1++;
		u2++;
	}
	return (0);
}
