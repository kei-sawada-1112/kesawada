/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:37:50 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/19 10:42:46 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

int	check_first_byte(unsigned char *str)
{
	if ((*str & 0b11111000) == 0b11110000)
		return (4);
	else if ((*str & 0b11110000) == 0b11100000)
		return (3);
	else if ((*str & 0b11100000) == 0b11000000)
		return (2);
	else
		return (1);
}

void	print_invalid_bytes(unsigned char *str, int *bytes,
							int *byte_idx, int pid)
{
	unsigned char	*tmp;

	tmp = str;
	str[0] = tmp[*byte_idx];
	tmp[*byte_idx] = '\0';
	ft_printf("%s", tmp);
	ft_memset((str) + 1, '\0', 4);
	*bytes = check_first_byte(str);
	*byte_idx = 0;
}

void	bin_to_char(t_client *client)
{
	static int	bytes;

	(client->bit_idx)++;
	if (client->bit_idx == 8)
	{
		if (client->byte_idx == 0)
			bytes = check_first_byte(client->str);
		else if (bytes >= 2 && (client->str[client->byte_idx] & 0b11000000) != 0b10000000)
			print_invalid_bytes(client->str, &bytes, &client->byte_idx, client->pid);
		if (++(client->byte_idx) == bytes)
		{
			if (client->str[0] == ENQ)
				kill(client->pid, SIGUSR1);
			else
				ft_printf("%s", client->str);
			bytes = 1;
			client->byte_idx = 0;
			if (client->str[0] == '\0')
			{
				kill(client->pid, SIGUSR1);
				client->pid = 0;
				return ;
			}
			ft_memset(client->str, '\0', 5);
		}
		client->bit_idx = 0;
	}
	usleep(100);
	kill(client->pid, SIGUSR2);
}

void	server_handler(int signum, siginfo_t *info, void *context)
{
	static t_client	client;

	// ft_printf("si_pid = %d\n", client.pid);
	if (client.pid == 0)
		client = initialize_client(client, info->si_pid);
	if (client.pid != info->si_pid)
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
	ft_printf("/*-server started-*/\nserver pid: %d\n", getpid());
	sa.sa_sigaction = server_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
