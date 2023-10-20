/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:03:05 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/20 11:09:44 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_BONUS_H
# define FT_MINITALK_BONUS_H

# include "ft_printf/includes/ft_printf_bonus.h"
# include <signal.h>
# include <stdio.h>
# include <unistd.h>

# define ENT 4
# define ENQ 5
# define ACK 6

typedef struct s_client {
    int				bit_idx;
	int				byte_idx;
	unsigned char	str[5];
}	t_client;

void	initialize_client(t_client *client);
int		check_first_byte(unsigned char *str);
void	print_invalid_bytes(unsigned char *str, int *bytes, int *byte_idx);

#endif
