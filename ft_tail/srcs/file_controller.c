/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:45:15 by kei               #+#    #+#             */
/*   Updated: 2023/09/13 15:53:32 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int open_file_or_stdin(const char *filename)
{
    if (!filename)
        return STDIN_FILENO;
    return open(filename, O_RDONLY);
}

char *dynamic_read(int fd)
{
    char	*buffer;
    size_t	total_read;
    size_t	current_block_size;
    ssize_t	bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE);
    if (!buffer) return (NULL);
	total_read = 0;
	current_block_size = BUFFER_SIZE;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		total_read += bytes_read;
		buffer = resize_buffer_if_needed(buffer, &current_block_size, total_read);
		if (!buffer) return NULL;
		bytes_read = read(fd, buffer + total_read, BUFFER_SIZE);
    }
    buffer[total_read] = '\0';
    return buffer;
}

char *resize_buffer_if_needed(char *buffer, size_t *current_block_size, size_t total_read)
{
	char *new_buffer;

	if (total_read < *current_block_size)
		return buffer;
	*current_block_size += BUFFER_SIZE;
	new_buffer = ft_realloc(buffer, total_read, *current_block_size);
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	return (new_buffer);
}

void free_resources(char *buffer, char **buffer_split, size_t size, int fd)
{
	free(buffer);
	free_memory((void **)buffer_split, size - 1);
	close(fd);
}
