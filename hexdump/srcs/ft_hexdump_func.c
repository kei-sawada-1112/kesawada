/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:50:57 by kei               #+#    #+#             */
/*   Updated: 2023/09/17 17:24:47 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include "libft.h"
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

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

void	display_filename(const char *filename)
{
	write(1, "==> ", 4);
	write(1, filename, ft_strlen(filename));
	write(1, " <==", 4);
	write(1, "\n", 1);
}

void	display_hexdump_error(char *filename)
{
	if (!filename)
		return ;
	write(1, "hexdump: ", 9);
	write(1, filename, ft_strlen(filename));
	if (is_directory(filename))
		write(1, ": Is a directory\n", 17);
	else if (errno == ENOENT)
		write(1, ": No such file or directory\n", 28);
	else if (errno == EACCES)
		write(1, ": Permission denied\n", 20);
	else
		write(1, ": Unexpected error\n", 19);
}
