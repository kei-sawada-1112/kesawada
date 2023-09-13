/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:05:13 by kei               #+#    #+#             */
/*   Updated: 2023/09/10 21:34:09 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"
#include <errno.h>
#include <sys/stat.h>

int	is_directory(const char *path)
{
	struct stat	buf;

	if (stat(path, &buf) == 0)
	{
		if (S_ISDIR(buf.st_mode))
			return (1);
	}
	return (0);
}

void	display_cat_error(char *filename)
{
	write(1, "cat: ", 5);
	write(1, filename, ft_strlen(filename));
	if (errno == ENOENT)
		write(1, ": No such file or directory\n", 28);
	else if (errno == EACCES)
		write(1, ": Permission denied\n", 20);
	else if (errno == EISDIR)
		write(1, ": Is a directory\n", 17);
	else
		write(1, ": Unexpected error\n", 19);
}

void	read_and_display_from_fd(int fd)
{
	char	buffer[1024];
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, 1024);
	while (bytes_read > 0)
	{
		write(1, buffer, bytes_read);
		bytes_read = read(fd, buffer, 1024);
	}
}

void	ft_cat(char *filename)
{
	int	fd;

	if (!filename)
	{
		read_and_display_from_fd(0);
		if (!isatty(STDIN_FILENO))
			return ;
	}
	else
	{
		if (is_directory(filename))
		{
			errno = EISDIR;
			display_cat_error(filename);
		}
		fd = open(filename, O_RDONLY);
		if (fd < 0)
			display_cat_error(filename);
		else
		{
			read_and_display_from_fd(fd);
			close(fd);
		}
	}
}
