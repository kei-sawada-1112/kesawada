/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:59:43 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/21 20:30:27 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	num;

	num = size * count;
	ret = malloc(num);
	if (!ret)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_bzero(ret, num);
	return (ret);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*str;
	int		i;

	str = (char *)ft_calloc(5, 5);
	i = 0;
	while (i < 35) 
	{
		str[i] = 'a' + i;
		i++;
	}
	printf("%s\n", str);
}
*/
