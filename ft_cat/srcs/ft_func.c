/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:44:35 by kei               #+#    #+#             */
/*   Updated: 2023/09/10 20:15:57 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}

int	ft_strcmp(char *str1, char *str2)
{
	unsigned char	*ustr1;
	unsigned char	*ustr2;

	ustr1 = (unsigned char *)str1;
	ustr2 = (unsigned char *)str2;
	while (*ustr1 && *ustr2)
	{
		if (*ustr1 == *ustr2)
		{
			ustr1++;
			ustr2++;
		}
		else
			return (*ustr1 - *ustr2);
	}
	return (*ustr1 - *ustr2);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*static_str;
	char		*token;

	if (!str)
		return (NULL);
	static_str = str;
	while (*static_str && *static_str == delim[0])
		static_str++;
	if (!*static_str)
		return (NULL);
	token = static_str;
	while (*static_str)
	{
		if (*static_str == delim[0])
		{
			*static_str = '\0';
			static_str++;
			return (token);
		}
		static_str++;
	}
	static_str = NULL;
	return (token);
}
