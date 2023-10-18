/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:11:32 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/18 12:30:05 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

t_client	*find_client(t_client *client, int pid)
{
	t_client *current;

	current = client;
	while (client)
	{
		if (current->pid == pid)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_client	*create_client(t_client *client, int pid)
{
	t_client *new_client;

	new_client = malloc(sizeof(t_client));
	if (!new_client)
		return (NULL);
	new_client->pid = pid;
	ft_memset(new_client->str, '\0', 5);
	new_client->bit_idx = 0;
	new_client->byte_idx = 0;
	if (!client)
	{
		client = new_client;
		return (client);
	}
	new_client->next = client;
	client = new_client;
	return (new_client);
}
