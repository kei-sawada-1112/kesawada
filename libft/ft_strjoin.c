/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:32:47 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/09 19:41:46 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	size_t	len1;
	size_t	len2;

	if (!s1)
		return (NULL);
	else if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = (char *)malloc(len1 + len2 + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, len1 + 1);
	ft_strlcat(ret, s2, len1 + len2 + 1);
	return (ret);
}
