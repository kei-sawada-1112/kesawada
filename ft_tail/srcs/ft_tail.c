/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:39:33 by kei               #+#    #+#             */
/*   Updated: 2023/09/13 10:23:16 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_tail(int argc, char **argv) {
	TailOptions	options;

	options.filenames = (char **)alloc_memory(argc - 2);
	if (!options.filenames)
		return ;
	if (argc == 3)
		ft_tail_no_option(argv[2]);
	else
	{
		parse_options(argc, argv, &options);
		execute_tail(&options);
	}
	if (options.filenames)
		free(options.filenames);
}

void	parse_options(int argc, char **argv, TailOptions *options)
{
	int		i;
	int 	file_index;
	char	*num_part;

	i = 2;
	file_index = 0;
	num_part = NULL;
	while (i < argc)
	{
		if (argv[i][0] == '-' && !options->file_count)
		{
			if (ft_strncmp(argv[i], "-n", 2) == 0)
			{
				if (argv[i][2])
					num_part = argv[i][2];
				else
					num_part = argv[++i];
				if (num_part[0] == '+')
				{
					options->lines = ft_atoi(&num_part[1]);
					options->plus_flag = 1;
				}
				else
					options->lines = ft_atoi(num_part);
			}
			else if (ft_strncmp(argv[i], "-b", 2) == 0)
			{
				// この場合はbytesオプションをセットする実装を行います。
				// （この例では実装は省略されています）
			}
		}
		else
		{
			options->filenames[file_index] = argv[i];
			options->file_count++;
			file_index++;
		}
		i++;
	}
}

void execute_tail(TailOptions *options)
{
	int		i;

	i = 0;
	while (i < options->file_count)
	{
		ft_tail_no_option(options->filenames[i]);
		i++;
		if (!(i == options->file_count))
			write(1, "\n", 1);
	}
}

void	ft_tail(char *filename)
{
	int		fd;
	char	*buffer;
	char	**buffer_split;
	size_t	length;
	size_t	size;

	if (!filename)
		fd = STDIN_FILENO;
	else
		fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		display_tail_error(filename);
		return;
	}
	buffer = dynamic_read(fd, &length);
	if (!buffer)
	{
		close(fd);
		return ;
    }
	buffer_split = ft_split(buffer, "\n");
	size = ft_count_elements(buffer_split);
	display_filename(filename);
	display_lines(buffer_split, size - 10, size);
	free(buffer);
	free_memory((void **)buffer_split, size - 1);
	close(fd);
}

char *dynamic_read(int fd, size_t *total_size) {
    char	*buffer;
	size_t	total_read;
	size_t	current_block_size;
	ssize_t	bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE);
    if (!buffer)
		return (NULL);
	total_read = 0;
	current_block_size = BUFFER_SIZE;
    while (1) {
		bytes_read = read(fd, buffer + total_read, BUFFER_SIZE);
        if (bytes_read < 0) {
            free(buffer);
            return (NULL);
		}
		total_read += bytes_read;
		if (bytes_read < BUFFER_SIZE)
			break;
		current_block_size += BUFFER_SIZE;
		char *new_buffer = ft_realloc(buffer, total_read, current_block_size);
		if (!new_buffer) {
			free(buffer);
			return (NULL);
		}
		buffer = new_buffer;
	}
	buffer[total_read] = '\0';
	*total_size = total_read;
	return (buffer);
}
