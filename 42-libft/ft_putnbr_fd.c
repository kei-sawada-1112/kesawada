/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:30:34 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/22 16:30:35 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

void    ft_putnbr_fd(int n, int fd)
{
    unsigned char   c;

    c = n + '0';
    if (fd >= 0)
        write(fd, &c, 1);
}
