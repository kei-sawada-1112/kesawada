/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:34:43 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/09 19:42:12 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	*start;
	char	*last;
	int		len;

	if (!s1)
		return (NULL);
	if (!*set)
		return (ft_strdup(s1));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	start = (char *)s1;
	last = (char *)s1 + ft_strlen(s1) - 1;
	while (last >= start && ft_strchr(set, *last))
		last--;
	len = last - start + 1;
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, start, len + 1);
	return (ret);
}
