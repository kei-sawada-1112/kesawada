/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:26:03 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/20 17:26:40 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ustr;
	size_t			i;

	ustr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ustr[i] = '\0';
		i++;
	}
}
