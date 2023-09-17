/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_contents.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:52:13 by kei               #+#    #+#             */
/*   Updated: 2023/09/17 14:11:53 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	display(t_options *options, char **buf_sp, size_t size, int index)
{
	if (options->file_count != 1 && !options->q_flag)
		display_filename(options->filenames[index]);
	if (options->plus_flag)
		display_lines(buf_sp, options->n, size);
	else
		display_lines(buf_sp, size - options->n, size);
}

void	display_n_option(t_options *options, int index)
{
	int		fd;
	char	*buffer;
	char	**buffer_split;
	size_t	size;

	fd = open_file_or_stdin(options->filenames[index]);
	if (fd < 0)
	{
		display_tail_error(options->filenames[index]);
		return ;
	}
	buffer = dynamic_read(fd);
	if (!buffer)
	{
		close(fd);
		return ;
	}
	buffer_split = ft_split(buffer, "\n");
	size = ft_count_elements(buffer_split);
	display(options, buffer_split, size, index);
	free(buffer);
	free_memory((void **)buffer_split, size - 1);
	close(fd);
}

void	display_c_option(t_options *options, int index)
{
	int		fd;
	char	*buffer;

	fd = open_file_or_stdin(options->filenames[index]);
	if (fd < 0)
	{
		display_tail_error(options->filenames[index]);
		return ;
	}
	buffer = dynamic_read(fd);
	if (!buffer)
	{
		close(fd);
		return ;
	}
	if (options->plus_flag)
		write (1, buffer + options->n, ft_strlen(buffer) - options->n);
	else
		write (1, buffer + ft_strlen(buffer) - options->n, options->n);
	free(buffer);
	close(fd);
}

void	display_b_option(t_options *options, int index)
{
	int		fd;
	int		bytes;
	char	*buffer;

	fd = open_file_or_stdin(options->filenames[index]);
	if (fd < 0)
	{
		display_tail_error(options->filenames[index]);
		return ;
	}
	buffer = dynamic_read(fd);
	if (!buffer)
	{
		close(fd);
		return ;
	}
	bytes = 512 * (options->n - 1);
	if (ft_strlen(buffer) < bytes)
		write (1, buffer, ft_strlen(buffer));
	if (options->plus_flag)
		write (1, buffer + bytes, ft_strlen(buffer) - bytes);
	else
		write (1, buffer + ft_strlen(buffer) - bytes, bytes);
	free(buffer);
	close(fd);
}

void	display_lines(char **buffer_split, int first, int last)
{
	size_t	len;

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
