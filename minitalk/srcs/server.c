/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:37:50 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/06 13:53:55 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static volatile sig_atomic_t	g_client_pid;

static void	bin_to_char(t_client *client)
{
	if (++client->bit_idx == 8)
	{
		client->bit_idx = 0;
		check_bytes(client);
		if (++(client->byte_idx) == client->bytes)
		{
			if (client->str[0] == ENQ)
				kill_and_catch_error(client, SIGUSR2, &g_client_pid);
			else if (client->str[0] == ENT)
			{
				kill_and_catch_error(client, SIGUSR1, &g_client_pid);
				g_client_pid = 0;
				client->pid = 0;
				return ;
			}
			else
				ft_printf("%s", client->str);
			initialize_client(client);
		}
	}
	usleep(100);
	kill_and_catch_error(client, SIGUSR1, &g_client_pid);
}

static void	process(t_client *client)
{
	unsigned int	sended_pid;
	unsigned int	signal;

	if (g_client_pid & (1U << 30))
	{
		sended_pid = g_client_pid & ~(1U << 30);
		signal = 2;
	}
	else
	{
		sended_pid = g_client_pid;
		signal = 1;
	}
	if (!client->pid)
	{
		initialize_client(client);
		client->pid = sended_pid;
	}
	if (client->pid != sended_pid)
		return ;
	client->str[client->byte_idx] <<= 1;
	if (signal == 2)
		client->str[client->byte_idx] |= 1;
	bin_to_char(client);
}

static void	observe_client(t_client *client)
{
	if (kill(client->pid & ~(1U << 30), 0) == -1 \
		&& kill(client->pid, 0) == -1)
	{
		ft_printf("%s\nConnection lost with Client: %u.\n%s\
Awaiting next client connection.\n%s", RED, client->pid, CYAN, RESET);
		g_client_pid = 0;
		client->pid = 0;
	}
}

static void	server_handler(int signum, siginfo_t *info, void *context)
{
	sig_atomic_t	encoded_pid;

	(void)context;
	encoded_pid = 0;
	if (signum == SIGUSR2)
		encoded_pid = info->si_pid | 1U << 30;
	else if (signum == SIGUSR1)
		encoded_pid = info->si_pid;
	g_client_pid = encoded_pid;
}

int	main(void)
{
	struct sigaction	sa;
	static t_client		client;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = server_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	show_minitalk_display(getpid());
	while (1)
	{
		if (g_client_pid)
		{
			process(&client);
			observe_client(&client);
		}
		sleep(1);
	}
}
