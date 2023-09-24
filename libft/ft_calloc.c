/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:59:43 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/24 13:01:29 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	num;

	num = 1;
	if (size == 0 || count == 0)
	{
		ret = malloc(1);
		if (!ret)
			return (NULL);
		return (ret);
	}
	else if (count > SIZE_MAX / size || size > SIZE_MAX / count)
		return (NULL);
	num = size * count;
	ret = malloc(num);
	if (!ret)
		return (NULL);
	ft_bzero(ret, num);
	return (ret);
}
