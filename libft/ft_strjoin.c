/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:32:47 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/25 20:33:10 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;

	if (!s1)
		return (NULL);
	ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, ft_strlen(s1) + 1);
	ft_strlcat(ret, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (ret);
}
