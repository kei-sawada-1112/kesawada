/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:11:32 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/20 16:09:19 by kesawada         ###   ########.fr       */
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
