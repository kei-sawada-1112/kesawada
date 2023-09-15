/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:08:04 by kei               #+#    #+#             */
/*   Updated: 2023/09/15 22:24:50 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	check_base(int base, char *nptr)
{
	if (base == 0)
	{
		if (*nptr == '0')
		{
			if (*(nptr + 1) == 'X' || *(nptr + 1) == 'x')
				base = 16;
			else
				base = 8;
		}
		else
			base = 10;
	}
	return (base);
}

static char	*create_base_str(int base)
{
	char	*str;
	int		i;

	str = (char *)malloc(base + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < base)
	{
		if (i < 10)
			str[i] = '0' + i;
		else
			str[i] = 'a' + (i - 10);
		i++;
	}
	str[i] = '\0';
	return (str);
}

static long int	convert_to_number(char *ptr, int base)
{
	long int	num;

	num = 0;
	while (*ptr)
	{
		if (*ptr >= '0' && *ptr <= '9')
			num = num * base + (*ptr - '0');
		else if (*ptr >= 'a' && *ptr <= 'a' + (base - 10 - 1))
			num = num * base + (10 + *ptr - 'a');
		else
			break ;
		ptr++;
	}
	return (num);
}

long int	ft_strtol(const char *nptr, char **endptr, int base)
{
	long int	num;
	char		*ptr;
	char		*str;
	int			sign;

	sign = 1;
	nptr = preprocess(nptr, &sign);
	base = check_base(base, (char *)nptr);
	if (base > 36 || base < 2)
		return (0);
	str = create_base_str(base);
	if (!str)
		return (0);
	ptr = ft_strpbrk(nptr, str);
	if (!ptr)
	{
		free(str);
		return (0);
	}
	num = convert_to_number(ptr, base);
	*endptr = ptr;
	free(str);
	return (num * sign);
}

unsigned long int	ft_strtoul(const char *nptr, char **endptr, int base)
{
	unsigned long int	num;
	char				*ptr;
	char				*str;
	int					sign;

	sign = 1;
	nptr = preprocess(nptr, &sign);
	base = check_base(base, (char *)nptr);
	if (base > 36 || base < 2)
		return (0);
	str = create_base_str(base);
	if (!str)
		return (0);
	ptr = ft_strpbrk(nptr, str);
	if (!ptr)
	{
		free(str);
		return (0);
	}
	num = (unsigned long int)convert_to_number(ptr, base);
	*endptr = ptr;
	free(str);
	return (num * sign);
}
