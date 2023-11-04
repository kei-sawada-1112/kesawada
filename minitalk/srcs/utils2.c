/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:04:53 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/04 18:38:17 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	check_bytes(t_client *client)
{
	if (client->byte_idx == 0)
		client->bytes = check_first_byte(client->str);
	else if (client->bytes >= 2 && \
		(client->str[client->byte_idx] & 0b11000000) != 0b10000000)
		print_invalid_bytes(client->str, &client->bytes, &client->byte_idx);
}

void	kill_and_catch_error(t_client *client, int signum, \
	volatile sig_atomic_t *g_client_pid)
{
	if (kill(client->pid, signum) == -1)
	{
		ft_printf("%s\nConnection lost with Client: %u.\n%s\
Awaiting next client connection.\n%s", RED, client->pid, CYAN, RESET);
		initialize_client(client);
		*g_client_pid = 0;
		client->pid = 0;
	}
}
