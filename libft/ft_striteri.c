/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:32:29 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/26 12:54:29 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	len;
	unsigned int	i;

	if (!s || !f)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
		f(i++, s++);
}
