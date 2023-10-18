/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:11:32 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/18 16:35:39 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

// t_client	*find_client(t_client *client, int pid)
// {
// 	// printf("find pid : %d\n", pid);
// 	// printf("client pid : %d\n", client->pid);
// 	while (client)
// 	{
// 		if (client->pid == pid)
// 			return (client);
// 		else if (!client->next)
// 			return (create_client(client, pid));
// 		else
// 			client = client->next;
// 	}
// 	return (NULL);
// }

t_client	initialize_client(t_client client, int pid)
{
	client.pid = pid;
	ft_memset(client.str, '\0', 5);
	client.bit_idx = 0;
	client.byte_idx = 0;
	return (client);
}
