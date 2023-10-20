/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:37:50 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/20 12:16:22 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

volatile int	g_client_pid;

static void	kill_and_catch_error(int pid, int signum, t_client *client)
{
	if (kill(pid, signum) == -1)
	{
		ft_printf("\nConnection lost with Client: %d.\nAwaiting next client connection.\n", pid);
		initialize_client(client);
		g_client_pid = 0;
	}
}

static void	bin_to_char(t_client *client)
{
	static int	bytes;

	(client->bit_idx)++;
	if (client->bit_idx == 8)
	{
		if (client->byte_idx == 0)
			bytes = check_first_byte(client->str);
		else if (bytes >= 2 && (client->str[client->byte_idx] & 0b11000000) != 0b10000000)
			print_invalid_bytes(client->str, &bytes, &client->byte_idx);
		if (++(client->byte_idx) == bytes)
		{
			if (client->str[0] == ENQ)
				kill_and_catch_error(g_client_pid, SIGUSR2, client);
			else if (client->str[0] == ENT)
			{
				kill_and_catch_error(g_client_pid, SIGUSR1, client);
				g_client_pid = 0;
				return ;
			}
			else
				ft_printf("%s", client->str);
			initialize_client(client);
		}
		client->bit_idx = 0;
	}
	usleep(100);
	kill_and_catch_error(g_client_pid, SIGUSR1, client);
}

void	server_handler(int signum, siginfo_t *info, void *context)
{
	static t_client	client;

	if (g_client_pid == 0)
	{
		initialize_client(&client);
		g_client_pid = info->si_pid;
	}
	if (g_client_pid != info->si_pid)
		return ;
	(void)context;
	client.str[client.byte_idx] <<= 1;
	if (signum == SIGUSR2)
		client.str[client.byte_idx] |= 1;
	bin_to_char(&client);
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	ft_printf("/*-Server started-*/\nServer pid: %d\n", getpid());
	sa.sa_sigaction = server_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		if (kill(g_client_pid, 0) == -1)
		{
			ft_printf("\nConnection lost with Client: %d.\nAwaiting next client connection.\n", g_client_pid);
			g_client_pid = 0;
		}
		sleep(3);
	}
}
