/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:58:13 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/23 16:34:20 by kei              ###   ########.fr       */
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
		s++;
    }
}
