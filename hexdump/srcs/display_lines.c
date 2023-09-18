/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:14:10 by kei               #+#    #+#             */
/*   Updated: 2023/09/18 12:11:25 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_hexdump.h"
#include "libft.h"

void	convert_and_display(unsigned char c, const char *base_chars)
{
	size_t	base;

	base = ft_strlen(base_chars);
	write (1, &base_chars[(c >> 4 & 0x0F) % base], 1);
	write (1, &base_chars[(c & 0x0F) % base], 1);
}

void	display_contents(char *line, size_t bytes)
{
	size_t	i;

	i = 0;
	while (i < bytes)
	{
		convert_and_display(line[i + 1], "0123456789abcdef");
		convert_and_display(line[i], "0123456789abcdef");
		if (i != bytes - 1)
			write (1, " ", 1);
		i += 2;
	}
	write (1, "\n", 1);
}

void	display_address(unsigned int address)
{
	char	buffer[7];
	int		i;

	i = 6;
	while (i >= 0)
	{
		buffer[i] = "0123456789abcdef"[address % 16];
		address /= 16;
		i--;
	}
	write(1, buffer, 7);
	write(1, " ", 1);
}

void	display_stdin(int bytes)
{
	char			*line;
	int				bytes_read;
	unsigned int	address;

	address = 0;
	line = (char *)malloc(bytes);
	if (!line)
		return ;
	bytes_read = read(0, line, bytes);
	while (bytes_read)
	{
		display_address(address);
		display_contents(line, bytes_read);
		bytes_read = read(0, line, bytes);
		address += bytes_read;
	}
	display_address(address);
	free(line);
}

void	display_lines(t_options *options, int index)
{
	char			*line;
	int				fd;
	char			*filename;
	int				bytes_read;
	unsigned int	address;

	address = 0;
	line = (char *)malloc(options->bytes);
	if (!line)
		return ;
	filename = options->filenames[index];
	if (!filename)
		return ;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		display_hexdump_error(filename);
		return ;
	}
	bytes_read = read(fd, line, options->bytes);
	while (bytes_read)
	{
		display_address(address);
		display_contents(line, bytes_read);
		address += bytes_read;
		bytes_read = read(fd, line, options->bytes);
	}
	address += bytes_read;
	display_address(address);
	write (1, "\n", 1);
	free(line);
	close(fd);
}
