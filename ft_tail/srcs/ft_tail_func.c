/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:12:44 by kei               #+#    #+#             */
/*   Updated: 2023/09/13 11:44:22 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
#include <errno.h>
#include <sys/stat.h>

void	display_tail_error(const char *filename)
{
	if (!filename)
		return ;
	write(1, "tail: ", 6);
	write(1, filename, ft_strlen(filename));
	if (errno == ENOENT)
		write(1, ": No such file or directory\n", 28);
	else if (errno == EACCES)
		write(1, ": Permission denied\n", 20);
	else
		write(1, ": Unexpected error\n", 19);
}

char	*get_next_line(char **start_pos)
{
	char	*newline_pos;
	char	*line;

	newline_pos = ft_strchr(*start_pos, '\n');
	if (!newline_pos)
	{
		if (**start_pos)
			return (ft_strdup(*start_pos));
		else
			return (NULL);
	}
	line = ft_strndup(*start_pos, newline_pos - *start_pos + 1);
	*start_pos = newline_pos + 1;
	return (line);
}

void	handle_lines(char *start_pos, char **lines, int *current_line)
{
	char	*line;

	line = get_next_line(&start_pos);
	while (line)
	{
		free(lines[*current_line]);
		lines[*current_line] = line;
		*current_line = (*current_line + 1) % 11;
		line = get_next_line(&start_pos);
	}
}

void display_filename(const char *filename)
{
    write(1, "==> ", 4);
    write(1, filename, ft_strlen(filename));
    write(1, " <==", 4);
    write(1, "\n", 1);
}

void	display_lines(char **buffer_split, int first, int last)
{
	size_t len;

	while (first <= last && buffer_split[first])
	{
		if (buffer_split[first] == NULL)
			len = 0;
		else
			len = ft_strlen(buffer_split[first]);
		write(1, buffer_split[first], len);
		write(1, "\n", 1);
		first++;
	}
}
