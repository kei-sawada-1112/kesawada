/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:03:05 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/04 18:39:12 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

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
	unsigned int	pid;
	unsigned int	bit_idx;
	unsigned int	byte_idx;
	unsigned int	bytes;
	unsigned char	str[5];
}	t_client;

void			show_minitalk_display(unsigned int pid);
void			initialize_client(t_client *client);
unsigned int	check_first_byte(unsigned char *str);
void			print_invalid_bytes(unsigned char *str, unsigned int *bytes, unsigned int *byte_idx);
void			kill_if_error_exit(unsigned int c, unsigned int pid);
void			check_bytes(t_client *client);
void			kill_and_catch_error(t_client *client, int signum, volatile sig_atomic_t *g_client_pid);

#endif
