/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:59:56 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/20 15:12:58 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

volatile int	g_receiver;

static void	kill_and_catch_error(unsigned int c, int pid)
{
	if (c & 128)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("%sServer connection lost! Aborting...\n%s", RED, RESET);
			exit(1);
		}
	}
	else if (kill(pid, SIGUSR1) == -1)
	{
		ft_printf("%sServer connection lost! Aborting...\n%s", RED, RESET);
		exit(1);
	}
}

static int	handshake(unsigned char c, int pid)
{
	int	bit_idx;
	int	i;

	bit_idx = 0;
	while (bit_idx++ < 8)
	{
		kill_and_catch_error(c, pid);
		i = 0;
		while (g_receiver == 0)
		{
			if (i++ == 500)
			{
				ft_printf("%sNo response from the server. Please wait a moment.\n%s",
					YELLOW, RESET);
				return (0);
			}
			usleep(100);
		}
		if (g_receiver == 2)
			return (1);
		g_receiver = 0;
		usleep(100);
		c <<= 1;
	}
	return (0);
}

static void	char_to_bin(unsigned char c, int pid)
{
	int	bit_idx;
	int	i;

	bit_idx = 0;
	while (bit_idx++ < 8)
	{
		kill_and_catch_error(c, pid);
		i = 0;
		while (g_receiver == 0)
		{
			if (i++ == 500)
			{
				ft_printf("%sSignal did not reach the server. ", YELLOW);
				ft_printf("Resending the bit.\n%s", RESET);
				kill_and_catch_error(c, pid);
			}
			usleep(100);
		}
		usleep(100);
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

int	main(int argc, char **argv)
{
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
	ft_printf("%sclient_pid: %s%d%s\n", CYAN, MAGENTA, client_pid, RESET);
	while (g_receiver == 0)
	{
		if (handshake(ENQ, server_pid))
			break ;
		ft_printf("%sAwaiting handshake with the server...\n%s", CYAN, RESET);
		sleep(3);
	}
	ft_printf("%sConnected to server: %d successfully!\n%s",
		GREEN, server_pid, RESET);
	ft_printf("%sSending text to the server...\n%s", CYAN, RESET);
	usleep(100);
	g_receiver = 0;
	i = 0;
	while (argv[2][i])
	{
		char_to_bin(argv[2][i], server_pid);
		i++;
	}
	char_to_bin(ENT, server_pid);
}
