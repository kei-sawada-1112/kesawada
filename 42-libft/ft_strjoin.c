/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:36:54 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/21 20:52:23 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;

	ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, ft_strlen(s1));
	ft_strlcat(ret, s2, ft_strlen(s1) + ft_strlen(s2));
	return (ret);
}
