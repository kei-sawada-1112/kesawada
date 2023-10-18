/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:59:56 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/18 11:45:15 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

volatile sig_atomic_t	g_receiver;

void	char_to_bin(unsigned char c, int pid)
{
	int	bit_idx;
	int	i;

	bit_idx = 0;
	while (bit_idx++ < 8)
	{
		if (c & 128)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i = 0;
		while (g_receiver == 0)
		{
			if (i++ == 50)
			{
				ft_printf("no response from server. exit.\n");
				exit(1);
			}
			usleep(100);
		}
		g_receiver = 0;
		usleep(100);
		c <<= 1;
	}
	return ;
}

void	client_handler(int signum)
{
	static int	i;
	(void)signum;

	g_receiver = 1;
	if (signum == SIGUSR2)
		++i;
	else if (signum == SIGUSR1)
		ft_printf("%d bytes context sent.\n", ++i);
}

int	main(int argc, char **argv)
{
	int					client_pid;
	int					server_pid;
	int					i;

	if (argc != 3)
	{
		ft_printf("usage: <command> <pid> <text>\n");
		return (1);
	}
	client_pid = getpid();
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, client_handler);
	signal(SIGUSR2, client_handler);
	i = 0;
	while (argv[2][i])
	{
		char_to_bin(argv[2][i], server_pid);
		i++;
	}
	char_to_bin('\0', server_pid);
}
