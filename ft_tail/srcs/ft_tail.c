/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:39:33 by kei               #+#    #+#             */
/*   Updated: 2023/09/13 15:57:34 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_tail(int argc, char **argv) {
	t_options	options;

	options.n = 10;
	options.file_count = 0;
	options.option_count = 0;
	options.plus_flag = 0;
	options.n_flag = 0;
	options.b_flag = 0;
	options.c_flag = 0;
	parse_options(argc, argv, &options);
	execute_tail(&options);
	free(options.filenames);
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
