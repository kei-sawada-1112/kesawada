/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:03:05 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/18 12:26:14 by kesawada         ###   ########.fr       */
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
    int				pid;
    int				bit_idx;
	int				byte_idx;
	unsigned char	str[5];
    struct s_client	*next;
}	t_client;

t_client	*create_client(t_client *client, int pid);
t_client	*find_client(t_client *client, int pid);

#endif
