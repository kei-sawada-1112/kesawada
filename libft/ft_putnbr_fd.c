/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:30:34 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/24 13:00:44 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;
	size_t	len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	str[len] = '\0';
	if (fd >= 0)
		write(fd, str, ft_strlen(str));
	free(str);
}
