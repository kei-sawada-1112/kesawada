/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:14:13 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/22 16:14:14 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

void    ft_putendl_fd(char *s, int fd)
{
    write(fd, "\n", 1);
    ft_putstr_fd(s, fd);
}
