/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:39:33 by kei               #+#    #+#             */
/*   Updated: 2023/09/13 15:23:43 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_tail(int argc, char **argv) {
	t_options	options;

	options.file_count = 0;
	options.option_count = 0;
	options.plus_flag = 0;
	options.n_flag = 0;
	options.b_flag = 0;
	options.c_flag = 0;
	// if (argc == 3)
	// 	display_no_option(argv[2]);
	// else
	// {
		parse_options(argc, argv, &options);
		execute_tail(&options);
		free(options.filenames);
	//}
}

void	parse_options(int argc, char **argv, t_options *options)
{
	int		i;
	int 	file_index;
	char	*num_part;

	i = 2;
	num_part = NULL;
	while (i < argc)
	{
		if (argv[i][0] == '-' && !options->file_count)
		{
			if (ft_strncmp(argv[i], "-n", 2) == 0)
			{
				options->option_count++;
				if (argv[i][2])
					num_part = &argv[i][2];
				else
				{
					num_part = argv[++i];
					options->option_count++;
				}
				if (num_part[0] == '+')
				{
					options->n = ft_atoi(&num_part[1]);
					options->plus_flag = 1;
				}
				else
					options->n = ft_atoi(num_part);
			}
			else if (ft_strncmp(argv[i], "-b", 2) == 0)
			{
				// この場合はbytesオプションをセットする実装を行います。
				// （この例では実装は省略されています）
			}
		}
		i++;
	}
	options->filenames = malloc(sizeof(char *) * (argc - 2 - options->option_count));
	if (!options->filenames)
		return ;
	i = 2 + options->option_count;
	file_index = 0;
	while (i < argc)
	{
		options->filenames[file_index] = argv[i];
		options->file_count++;
		file_index++;
		i++;
	}
	printf("file_count: %d\n", options->file_count);
	printf("option_count: %d\n", options->option_count);
}

void execute_tail(t_options *options)
{
	int		i;

	i = 0;
	while (i < options->file_count)
	{
		//if (options->n_flag)
			display_n_option(options, i);
		//else
		//	display_no_option(options->filenames[i]);
		i++;
		if (!(i == options->file_count))
			write(1, "\n", 1);
	}
}

void	display_n_option(t_options *options, int index)
{
	int		fd;
	char	*buffer;
	char	**buffer_split;
	size_t	length;
	size_t	size;

	if (!options->filenames[index])
		fd = STDIN_FILENO;
	else
		fd = open(options->filenames[index], O_RDONLY);
	if (fd < 0)
	{
		display_tail_error(options->filenames[index]);
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
	if (options->file_count != 1)
		display_filename(options->filenames[index]);
	if (options->plus_flag)
		display_lines(buffer_split, options->n, size);
	else
		display_lines(buffer_split, size - options->n, size);
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
