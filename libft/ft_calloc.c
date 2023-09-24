/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:59:43 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/24 19:43:37 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"

#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	num;

	num = 1;

	if (size && count >= SIZE_MAX / size)
		return (NULL);
	num = size * count;
	if (num == SIZE_MAX)
		return (NULL);
	ret = malloc(num);
	if (!ret)
	 	return (NULL);
	ft_bzero(ret, num);
	return (ret);
}
