/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:35:42 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/25 18:35:43 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (fd >= 0)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
	else
		return ;
}
