/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:36:00 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/30 15:27:45 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_ms	*init_ms(int fd)
{
	t_ms	*new;

	new = malloc(sizeof(t_ms));
	if (!new)
		return (NULL);
	new->buffer = malloc(BUFFER_SIZE + (size_t)1);
	if (!new->buffer)
	{
		free(new);
		return (NULL);
	}
	new->bytes_read = read(fd, new->buffer, BUFFER_SIZE);
	new->buffer[new->bytes_read] = '\0';
	new->fd = fd;
	new->state = LETTER;
	new->tmp_buffer = NULL;
	new->tmp_len = 0;
	new->copied_len = 0;
	new->count = 0;
	new->next = NULL;
	return (new);
}

static void	delete_current_ms(t_ms *dummy, t_ms *c_ms)
{
	t_ms	*prev;

	prev = dummy;
	while (prev->next && prev->next != c_ms)
		prev = prev->next;
	if (!prev->next)
		return ;
	prev->next = c_ms->next;
	free(c_ms);
	c_ms = NULL;
}

static int	endline_function(t_ms *dummy, t_ms *ms, char **next_line)
{
	if (!ms->count && !ms->tmp_len)
	{
		if (ms->tmp_buffer)
		{
			free(ms->tmp_buffer);
			ms->tmp_buffer = NULL;
		}
		if (ms->buffer)
		{
			free(ms->buffer);
			ms->buffer = NULL;
		}
		delete_current_ms(dummy, ms);
		return (0);
	}
	set_next_line(ms, next_line);
	return (1);
}

static t_ms	*get_current_ms(t_ms *ms, int fd)
{
	t_ms	*current;
	t_ms	*prev;

	current = ms;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		prev = current;
		current = current->next;
	}
	current = init_ms(fd);
	prev->next = current;
	return (current);
}

char	*get_next_line(int fd)
{
	static t_ms	dummy;
	char		*next_line;
	t_ms		*c_ms;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	dummy.fd = INT_MIN;
	c_ms = get_current_ms(&dummy, fd);
	if (!c_ms)
		return (NULL);
	while (1)
	{
		if (c_ms->state == LETTER)
			read_letter(c_ms);
		else if (c_ms->state == NEED_READ)
			re_read(c_ms);
		else if (c_ms->state == NEWLINE || c_ms->state == GNL_EOF)
		{
			if (!endline_function(&dummy, c_ms, &next_line))
				return (NULL);
			break ;
		}
	}
	return (next_line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	int fd1;
// 	int	fd2;
// 	int	fd3;
// int i = 0;
// char	*str1;
// char	*str2;
// char	*str3;
// 	fd1 = open("gnlTester/files/41_with_nl", O_RDONLY);
// 	fd2 = open("gnlTester/files/42_with_nl", O_RDONLY);
// 	fd3 = open("gnlTester/files/43_with_nl", O_RDONLY);
// 	while (i < 3)
// 	{
// 		str1 = get_next_line(fd1);
// 		str2 = get_next_line(fd2);
// 		str3 = get_next_line(fd3);
// 		printf("%s", str1);
// 		printf("%s", str2);
// 		printf("%s", str3);
// 		free (str1);
// 		free (str2);
// 		free (str3);
// 		i++;
// 	}
// 	// system("leaks a.out");
// }
