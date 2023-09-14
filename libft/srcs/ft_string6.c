/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:42:24 by kei               #+#    #+#             */
/*   Updated: 2023/09/14 21:37:21 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strcspn(const char *str, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (reject[j])
		{
			if (str[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

char	*ft_strtok_r(char *str, const char *delim, char **saveptr)
{
	char	*token;

	if (str)
		*saveptr = str;
	if (!*saveptr)
		return (NULL);
	while (**saveptr && ft_strchr(delim, **saveptr))
		(*saveptr)++;
	token = *saveptr;
	while (**saveptr && !ft_strchr(delim, **saveptr))
		(*saveptr)++;
	if (**saveptr)
	{
		**saveptr = '\0';
		(*saveptr)++;
	}
	if (token == *saveptr)
		return (NULL);
	return (token);
}

static double	get_frac(const char **nptr)
{
	double	frac;
	int		div;

	frac = 0.0;
	div = 10;
	while (**nptr >= '0' && **nptr <= '9')
	{
		frac += (**nptr - '0') / (double)div;
		div *= 10;
		(*nptr)++;
	}
	return (frac);
}

double	ft_atof(const char *nptr)
{
	double	res;
	int		sign;

	res = 0.0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	if (*nptr == '.')
	{
		nptr++;
		res += get_frac(&nptr);
	}
	return (sign * res);
}
