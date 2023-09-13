/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:39:33 by kei               #+#    #+#             */
/*   Updated: 2023/09/13 11:47:15 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_tail(int argc, char **argv) {
	t_options	options;

	options.filenames = (char **)alloc_memory(argc - 2);
	if (!options.filenames)
		return ;
	if (argc == 3)
		display_no_option(argv[2]);
	else
	{
		parse_options(argc, argv, &options);
		execute_tail(&options);
	}
	if (options.filenames)
		free(options.filenames);
}

void execute_tail(t_options *options)
{
	int		i;

	i = 0;
	while (i < options->file_count)
	{
		if (options->n_flag)
			display_n_option(options, i);
		else
			display_no_option(options->filenames[i]);
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
	size_t	size;

	fd = open_file(options->filenames[index]);
	if (fd < 0)
		return;
	buffer = read_file_content(fd);
	if (!buffer)
		return;
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
}

void	display_no_option(char *filename)
{
	int		fd;
	char	*buffer;
	char	**buffer_split;
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
	buffer = dynamic_read(fd);
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
