/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:37:50 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/18 00:12:55 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

volatile sig_atomic_t g_received = 0;

void	bin_to_char(int signum, char *c, int *i, int pid)
{
	*c <<= 1;
	if (signum == SIGUSR2)
		*c |= 1;
	(*i)++;
	if (*i == 8)
	{
		ft_printf("%c", *c);
		*i = 0;
		if (*c == '\0')
		{
			kill(pid, SIGUSR1);
			return ;
		}
	}
	usleep(100);
	kill(pid, SIGUSR2);
}

void	server_handler(int signum, siginfo_t *info, void *context)
{
	static int	pid;
	static int	i;
	static char	c;
	static int	current_pid;

	(void)context;
	if (!pid)
		pid = info->si_pid;
	current_pid = info->si_pid;
	if (pid != current_pid)
	{
		pid = current_pid;
		i = 0;
		c = 0;
	}
	bin_to_char(signum, &c, &i, pid);
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
		sleep(1);
}
