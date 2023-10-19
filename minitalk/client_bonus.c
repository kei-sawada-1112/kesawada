/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:59:56 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/19 10:54:50 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

volatile int	g_receiver;

volatile int	g_connected;

void	handshake(unsigned char c, int pid)
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
				ft_printf("cannot reach to server. try again...\n");
				return ;
			}
			usleep(100);
		}
		g_receiver = 0;
		usleep(100);
		c <<= 1;
	}
	return ;
}

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
	if (signum == SIGUSR1)
	{
		// ft_printf("%d bit(s) context sent.\n", ++i - 8);
		if (g_connected == 0)
			ft_printf("Hand shake succeeded!\n");
		g_connected = 1;
	}
}

int	main(int argc, char **argv)
{
	static int	connected;
	int			client_pid;
	int			server_pid;
	int			i;

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
	while (g_connected == 0)
	{
		// char_to_bin(ENQ, server_pid);
		ft_printf("wait for handshaking to server...\n");
		handshake(ENQ, server_pid);
		if (g_connected == 1)
			break ;
		sleep(5);
	}
	ft_printf("Connect to server: %d succeeded. Start to send message...\n", server_pid);
	g_receiver = 0;
	i = 0;
	while (argv[2][i])
	{
		char_to_bin(argv[2][i], server_pid);
		i++;
	}
	char_to_bin('\0', server_pid);
}
