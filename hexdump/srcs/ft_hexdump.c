/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:26:11 by kei               #+#    #+#             */
/*   Updated: 2023/09/18 11:40:29 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	execute_hexdump(t_options *options)
{
	int	i;

	i = 0;
	while (i < options->file_count)
	{
		// if (options->flag == 'n')
		// 	display_n_option(options, i);
		// else if (options->flag == 'c')
		// 	display_c_option(options, i);
		// else if (options->flag == 'b')
		// 	display_b_option(options, i);
		// else
			display_lines(options, i);
		i++;
		if (!(i == options->file_count))
			write(1, "\n", 1);
	}
}

void	ft_hexdump(int argc, char **argv)
{
	t_options	options;

	options.filenames = (char **)malloc(sizeof(char *) * (argc - 2));
	if (argc == 2)
	{
		display_stdin(16);
//		if (!isatty(STDIN_FILENO))
		return ;
	}
	options.n = argc;
	options.file_count = 1;
	options.option_count = 0;
	options.bytes = 16;
	options.filenames = (char **)malloc(sizeof(char *) * (argc - 2));
	options.filenames[0] = argv[2];

	// if (!parse_options(argc, argv, &options))
	// 	return ;
	execute_hexdump(&options);
	free(options.filenames);
}
