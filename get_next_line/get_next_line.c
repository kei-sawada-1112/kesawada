/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:36:00 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/03 13:04:25 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

void	init_ms(t_ms *ms)
{
	ms->buffer = NULL;
	ms->tmp_buffer = NULL;
	ms->bytes_read = 0;
	ms->capacity = BUFFER_SIZE;
	ms->copied_len = 0;
	ms->count = 0;
	ms->start_pos = 0;
	ms->state = LETTER;
	ms->tmp_len = 0;
}

char	*get_next_line(int fd)
{
	static t_ms	ms;
	char		*next_line;

	if (!ms.buffer)
	{
		init_ms(&ms);
		ms.buffer = (char *)malloc(BUFFER_SIZE + 1);
		ms.bytes_read = read(fd, ms.buffer, BUFFER_SIZE);
		ms.buffer[BUFFER_SIZE] = '\0';
	}
	next_line = NULL;
	while (1)
	{
		if (ms.state == LETTER)
			read_letter(&ms);
		else if (ms.state == NEWLINE)
		{
			set_next_line(&ms, &next_line);
			return (next_line);
		}
		else if (ms.state == NEED_READ)
		{
			set_tmp_buffer(&ms);
			re_read(&ms, fd);
		}
		else
		{
			set_next_line(&ms, &next_line);
			return (next_line);
		}
	}
	return (next_line);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i = 0;
	char	*next_line;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	next_line = NULL;
	while (fd > 0 && i < 100)
	{
		next_line = get_next_line(fd);
		printf("%s", next_line);
		free(next_line);
		i++;
	}
	//system("leaks get_next_line");
}

