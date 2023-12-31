/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:13:41 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/22 14:14:02 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char    nibai(unsigned int index, char c)
{
    c = index * c;
    return (c);
}

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char            *ret;
    unsigned int    len;
    unsigned int    i;

    len = ft_strlen(s);
    ret = (char *)malloc(len + 1);
    if (!ret)
        return (NULL);
    i = 0;
    while (i < len)
    {
        ret[i] = f(i, s[i]);
        i++;
    }
    ret[i] = '\0';
    return (ret);
}