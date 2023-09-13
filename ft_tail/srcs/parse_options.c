/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:33:23 by kei               #+#    #+#             */
/*   Updated: 2023/09/13 17:17:33 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	set_filenames(int argc, char **argv, t_options *options, int i)
{
	int	file_index;

	file_index = 0;
	i = 2 + options->option_count;
	while (i < argc)
	{
		options->filenames[file_index] = argv[i];
		file_index++;
		i++;
	}
}

int	parse_options(int argc, char **argv, t_options *options)
{
	int		i;

	i = 2;
	while (i < argc)
	{
		if (argv[i][0] == '-' && !options->file_count)
		{
			options->option_count++;
			if (ft_strncmp(argv[i], "-n", 2) == 0)
				options->n_flag = 1;
			else if (ft_strncmp(argv[i], "-b", 2) == 0)
				options->b_flag = 1;
			if (!check_options(argv, options, &i))
				return (0);
		}
		i++;
	}
	options->file_count = argc - 2 - options->option_count;
	options->filenames = malloc(sizeof(char *) * options->file_count);
	if (!options->filenames)
		return (0);
	set_filenames(argc, argv, options, i);
	return (1);
}

int	check_options(char **argv, t_options *options, int *i)
{
	char	*num_part;

	if (argv[*i][2])
		num_part = &argv[*i][2];
	else
	{
		num_part = argv[++(*i)];
		options->option_count++;
	}
	if (!is_valid_number(num_part))
	{
		write (1, "tail: illegal offset -- ", 24);
		write (1, num_part, ft_strlen(num_part));
		write (1, "\n", 1);
		return (0);
	}
	if (num_part[0] == '+')
	{
		options->n = ft_atoi(&num_part[1]);
		options->plus_flag = 1;
	}
	else
		options->n = ft_atoi(num_part);
	return (1);
}

int	is_valid_number(char *num)
{
	if (num[0] == '+')
		num++;
	while (*num)
	{
		if (!(*num >= '0' && *num <= '9'))
			return (0);
		num++;
	}
	return (1);
}
