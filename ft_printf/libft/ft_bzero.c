/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:26:03 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/09 19:39:53 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
