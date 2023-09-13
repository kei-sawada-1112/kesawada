/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:15:20 by kei               #+#    #+#             */
/*   Updated: 2023/09/13 11:32:31 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <ft_tail.h>

int	open_file(const char *filename)
{
	int	fd;

	if (!filename)
		return (STDIN_FILENO);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		display_tail_error(filename);
		return (-1);
	}
	return (fd);
}

char	*read_file_content(int fd)
{
	char	*buffer;

	buffer = dynamic_read(fd);
	close(fd);
	return (buffer);
}

char *expand_buffer(char *buffer, size_t total_read, size_t *current_block_size) {
    *current_block_size += BUFFER_SIZE;
    char *new_buffer = ft_realloc(buffer, total_read, *current_block_size);
    if (!new_buffer) {
        free(buffer);
    }
    return new_buffer;
}

char *dynamic_read(int fd) {
    char	*buffer;
    size_t	total_read = 0;
    size_t	current_block_size = BUFFER_SIZE;
    ssize_t bytes_read;

    buffer = (char *)malloc(BUFFER_SIZE);
    if (!buffer) return (NULL);

    while (1) {
        bytes_read = read(fd, buffer + total_read, BUFFER_SIZE);
        if (bytes_read < 0) {
            free(buffer);
            return (NULL);
        }
        total_read += bytes_read;
        if (bytes_read < BUFFER_SIZE) break;
        buffer = expand_buffer(buffer, total_read, &current_block_size);
        if (!buffer) return (NULL);
    }
    buffer[total_read] = '\0';
    return (buffer);
}
