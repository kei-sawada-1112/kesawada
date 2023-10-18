/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:37:50 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/18 12:14:08 by kesawada         ###   ########.fr       */
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

void	print_invalid_bytes(unsigned char **str, int *bytes,
							int *byte_idx, int pid)
{
	unsigned char	*tmp;

	tmp = *str;
	(*str)[0] = tmp[*byte_idx];
	tmp[*byte_idx] = '\0';
	ft_printf("%s", tmp);
	ft_memset((*str) + 1, '\0', 4);
	*bytes = check_first_byte(*str);
	*byte_idx = 0;
}

void	bin_to_char(unsigned char *str, int *i, int *byte_idx, int pid)
{
	static int	bytes;

	(*i)++;
	if (*i == 8)
	{
		if (*byte_idx == 0)
			bytes = check_first_byte(str);
		else if (bytes >= 2 && (str[*byte_idx] & 0b11000000) != 0b10000000)
			print_invalid_bytes(&str, &bytes, byte_idx, pid);
		if (++(*byte_idx) == bytes)
		{
			ft_printf("%s", str);
			bytes = 1;
			*byte_idx = 0;
			if (str[0] == '\0' || *byte_idx == 4)
			{
				kill(pid, SIGUSR1);
				return ;
			}
			ft_memset(str, '\0', 5);
		}
		*i = 0;
	}
	usleep(100);
	kill(pid, SIGUSR2);
}

void	server_handler(int signum, siginfo_t *info, void *context)
{
	static t_client	client;
	static int				pid;
	static int				i;
	static int				byte_idx;
	static unsigned char	str[5];
	static int				current_pid;

	(void)context;
	if (!pid)
		pid = info->si_pid;
	current_pid = info->si_pid;
	if (pid != current_pid)
	{
		pid = current_pid;
		ft_memset(str, '\0', 5);
		i = 0;
	}
	str[byte_idx] <<= 1;
	if (signum == SIGUSR2)
		str[byte_idx] |= 1;
	bin_to_char(str, &i, &byte_idx, pid);
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
