/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:05:14 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/24 13:00:10 by kei              ###   ########.fr       */
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
