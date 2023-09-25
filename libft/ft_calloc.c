/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:30:19 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/25 18:30:22 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	num;

	num = 1;
	if (!size || !count)
		return (ft_calloc(1, 1));
	if (size > SIZE_MAX / count && count > SIZE_MAX / size)
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
