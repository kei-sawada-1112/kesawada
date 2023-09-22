/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:58:13 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/22 15:58:14 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int    len;
    unsigned int    i;
    
    len = ft_strlen(s);
    i = 0;
    while (i < len)
    {
        f(i, s);
        i++;
    }
}
