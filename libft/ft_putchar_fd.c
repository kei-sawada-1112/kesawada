/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:34:45 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/25 18:34:46 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (fd >= 0)
	{
		if (c >= 0 && c <= 127)
			write(fd, &uc, 1);
		else if (uc >= 128 && uc <= 255)
			write(fd, &uc, 2);
	}
	else
		return ;
}
