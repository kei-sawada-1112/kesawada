/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:03:05 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/18 12:13:16 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_BONUS_H
# define FT_MINITALK_BONUS_H

# include "libft/libft.h"
# include "ft_printf/includes/ft_printf_bonus.h"
# include <signal.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_client {
    pid_t			pid;
    unsigned char	*data;
    int				bit_idx;
    struct s_client	*next;
}	t_client;

#endif
