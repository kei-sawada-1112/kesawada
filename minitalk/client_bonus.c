/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:59:56 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/19 20:46:56 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

volatile int	g_receiver;

int	handshake(unsigned char c, int pid)
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
			if (i++ == 500)
			{
				ft_printf("no response from server. try again...\n");
				return (0);
			}
			usleep(100);
		}
		if (g_receiver == 2)
			return(1);
		g_receiver = 0;
		usleep(100);
		c <<= 1;
	}
	return (0);
}

void	char_to_bin(unsigned char c, int pid)
{
	int	bit_idx;
	int	i;

	bit_idx = 0;
	while (bit_idx++ < 8)
	{
		if (c & 128)
			if (kill(pid, SIGUSR2))
			{
				// error message
				ft_putstr_fd("error message", 2);
				exit(1);
			};
		else
			kill(pid, SIGUSR1);
		i = 0;
		while (g_receiver == 0)
		{
			if (i++ == 500)
			{
				// ft_printf("no response from server. exit.\n");
				ft_printf("no response from server. send bit again.\n");
				if (c & 128)
					kill(pid, SIGUSR2);
				else
					kill(pid, SIGUSR1);
			}
			usleep(100);
		}
		usleep(100);
		c <<= 1;
		g_receiver = 0;
	}
	return ;
}

void	client_handler(int signum)
{
	static int	i;
	(void)signum;

	//g_receiver = 1;
	if (signum == SIGUSR2)
	{
		g_receiver = 2;
	}
	if (signum == SIGUSR1)
		g_receiver = 1;// ft_printf("%d byte(s) context sent.\n", (++i - 16) / 8);
}

int	main(int argc, char **argv)
{
	static int	connected;
	int			client_pid;
	int			server_pid;
	int			i;

	g_receiver = 0;
	if (argc != 3)
	{
		ft_printf("usage: <command> <pid> <text>\n");
		return (1);
	}
	client_pid = getpid();
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, client_handler);
	signal(SIGUSR2, client_handler);
	ft_printf("client_pid: %d\n", client_pid);
	while (g_receiver == 0)
	{
		if (handshake(ENQ, server_pid))
			break ;
		ft_printf("wait for handshaking to server...\n");
		sleep(3);
	}
	ft_printf("connect to server: %d succeeded!\nstart to send context...\n", server_pid);
	usleep(100);
	g_receiver = 0;
	i = 0;
	while (argv[2][i])
	{
		char_to_bin(argv[2][i], server_pid);
		i++;
	}
	char_to_bin('\0', server_pid);
}
