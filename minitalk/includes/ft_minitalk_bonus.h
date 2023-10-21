/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:03:05 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/21 10:51:03 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_BONUS_H
# define FT_MINITALK_BONUS_H

# include "ft_printf.h"
# include <signal.h>
# include <unistd.h>

# define ENT 4
# define ENQ 5

# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define RESET   "\033[0m"

typedef struct s_client {
	int				bit_idx;
	int				byte_idx;
	int				bytes;
	unsigned char	str[5];
}	t_client;

void	show_minitalk_display(int pid);
void	initialize_client(t_client *client);
int		check_first_byte(unsigned char *str);
void	print_invalid_bytes(unsigned char *str, int *bytes, int *byte_idx);
void	kill_if_error_exit(unsigned int c, int pid);

#endif
