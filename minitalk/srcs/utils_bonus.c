/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:11:32 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/04 19:16:43 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

void	show_minitalk_display(unsigned int pid)
{
	ft_printf("%s╭─────────────────────────────\
──────────────────────────────╮\n", CYAN);
	ft_printf("│                      Minitalk \
Server                      │\n");
	ft_printf("│───────────────────────────────\
────────────────────────────│\n");
	ft_printf("│                               \
                            │\n");
	ft_printf("│    Server PID: %s%-43d%s\
│\n", MAGENTA, pid, CYAN);
	ft_printf("│                               \
                            │\n");
	ft_printf("│    This program receives and d\
isplays client messages.    │\n");
	ft_printf("│    UTF-8 Encoding Supported.  \
                            │\n");
	ft_printf("│                               \
                            │\n");
	ft_printf("╰───────────────────────────────\
────────────────────────────╯%s\n", RESET);
}

void	initialize_client(t_client *client)
{
	ft_memset(client->str, '\0', 5);
	client->bit_idx = 0;
	client->byte_idx = 0;
	client->bytes = 0;
}

unsigned int	check_first_byte(unsigned char *str)
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

void	print_invalid_bytes(unsigned char *str, unsigned int *bytes, \
		unsigned int *byte_idx)
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

void	kill_if_error_exit(unsigned int c, unsigned int pid)
{
	if (c & 128)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("%sServer connection lost!\
 Aborting...\n%s", RED, RESET);
			exit(1);
		}
	}
	else if (kill(pid, SIGUSR1) == -1)
	{
		ft_printf("%sServer connection lost!\
 Aborting...\n%s", RED, RESET);
		exit(1);
	}
}
