/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:05:11 by kei               #+#    #+#             */
/*   Updated: 2023/09/14 12:43:23 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strcat(char *s1, const char *s2)
{
	char *ret;

	ret = s1;
	if (!*s2)
		return (s1);
	while (*s1)
		s1++;
	while (*s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (ret);
}

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *ret;

	ret = s1;
	if (!*s2)
		return (s1);
	while (*s1)
		s1++;
	while (*s2 && n > 0)
	{
		*s1++ = *s2++;
		n--;
	}
	*s1 = '\0';
	return (ret);
}

char	*ft_strcpy(char *s1, const char *s2)
{
	char	*ret;

	ret = s1;
	while (*s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (ret);
}

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	while (i < n)
	{
		s1[i] = '\0';
		i++;
	}
	return (s1);
}


