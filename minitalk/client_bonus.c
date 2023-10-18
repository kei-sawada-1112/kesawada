/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:59:56 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/18 21:00:51 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

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
			if (g_receiver == 1)
				break ;
			if (i++ == 5000)
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
		ft_printf("%d bit(s) context sent.\n", ++i - 8);
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
	while (g_receiver == 0)
	{
		// char_to_bin(ENQ, server_pid);
		ft_printf("client_pid: %d\n", client_pid);
		kill(server_pid, SIGUSR1);
		usleep(10000);
		kill(server_pid, SIGUSR1);
		usleep(10000);
		kill(server_pid, SIGUSR1);
		usleep(10000);
		kill(server_pid, SIGUSR1);
		usleep(10000);
		kill(server_pid, SIGUSR1);
		usleep(10000);
		kill(server_pid, SIGUSR2);
		usleep(10000);
		kill(server_pid, SIGUSR1);
		usleep(10000);
		kill(server_pid, SIGUSR1);
		usleep(10000);
		ft_printf("wait for sending...\n");
	}
	g_receiver = 0;
	i = 0;
	while (argv[2][i])
	{
		char_to_bin(argv[2][i], server_pid);
		i++;
	}
	char_to_bin('\0', server_pid);
}
