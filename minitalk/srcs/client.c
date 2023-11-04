/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:59:56 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/04 19:13:22 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static volatile sig_atomic_t	g_receiver;

static int	handshake(unsigned char c, int pid)
{
	int	bit_idx;
	int	i;

	bit_idx = 0;
	while (bit_idx++ < 8)
	{
		kill_if_error_exit(c, pid);
		i = 0;
		while (g_receiver == 0)
		{
			if (i++ == 500)
			{
				ft_printf("%sNo response from the server.\
 Please wait a moment.\n%s",
					YELLOW, RESET);
				return (0);
			}
			usleep(100);
		}
		if (g_receiver == 2)
			return (1);
		g_receiver = 0;
		usleep(10000);
		c <<= 1;
	}
	return (0);
}

static void	send_binary(unsigned char c, int pid)
{
	int	bit_idx;
	int	i;

	bit_idx = 0;
	while (bit_idx++ < 8)
	{
		kill_if_error_exit(c, pid);
		i = 0;
		while (g_receiver == 0)
		{
			if (i++ == 500)
			{
				ft_printf("%sSignal did not reach the server. \
Resending the bit.\n%s", YELLOW, RESET);
				kill_if_error_exit(c, pid);
			}
			usleep(100);
		}
		usleep(20);
		c <<= 1;
		g_receiver = 0;
	}
	return ;
}

static void	client_handler(int signum)
{
	(void)signum;
	if (signum == SIGUSR2)
		g_receiver = 2;
	if (signum == SIGUSR1)
		g_receiver = 1;
}

static void	connect_server(int pid, char **argv)
{
	int	i;

	i = 0;
	ft_printf("%sConnected to server: %d\
 successfully!\n%s", GREEN, pid, RESET);
	ft_printf("%sSending text to the\
 server...\n%s", CYAN, RESET);
	usleep(10000);
	g_receiver = 0;
	while (argv[2][i])
	{
		send_binary(argv[2][i], pid);
		i++;
	}
	send_binary(ENT, pid);
}

int	main(int argc, char **argv)
{
	int			server_pid;

	if (argc != 3)
	{
		ft_printf("usage: <command> <pid> <text>\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, client_handler);
	signal(SIGUSR2, client_handler);
	ft_printf("%sclient_pid: %s%d%s\n", CYAN, MAGENTA, getpid(), RESET);
	while (g_receiver == 0)
	{
		if (handshake(ENQ, server_pid))
			break ;
		ft_printf("%sAwaiting handshake with\
 the server...\n%s", CYAN, RESET);
		sleep(1);
	}
	connect_server(server_pid, argv);
}
