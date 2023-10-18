/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:11:32 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/18 19:56:44 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

t_client	initialize_client(t_client client, int pid)
{
	if (pid == 0)
		ft_printf("-----------------------pid error-------------------------\n");
	client.pid = pid;
	ft_memset(client.str, '\0', 5);
	client.bit_idx = 0;
	client.byte_idx = 0;
	return (client);
}

