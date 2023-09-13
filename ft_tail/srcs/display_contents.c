/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_contents.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:52:13 by kei               #+#    #+#             */
/*   Updated: 2023/09/13 17:29:05 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	display(t_options *options, char **buf_sp, size_t size, int index)
{
	if (options->file_count != 1)
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
