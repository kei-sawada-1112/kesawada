/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:46:37 by kei               #+#    #+#             */
/*   Updated: 2023/09/13 11:48:26 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	parse_n_option(char **argv, int *i, t_options *options)
{
	char	*num_part;

	options->n_flag = 1;
	if (argv[*i][2])
		num_part = (argv[*i] + 2);
	else
		num_part = argv[++(*i)];

	if (num_part[0] == '+')
	{
		options->n = ft_atoi(&num_part[1]);
		options->plus_flag = 1;
	}
	else
		options->n = ft_atoi(num_part);
}

// void	parse_b_option(char **argv, int *i, t_options *options)
// {
// 	// TODO: Implement -b option parsing
//}

void	parse_filenames(char **argv, int *i, t_options *options)
{
	options->filenames[options->file_count] = argv[*i];
	options->file_count++;
}

void	parse_options(int argc, char **argv, t_options *options)
{
	int	i;

	i = 2;
	while (i < argc)
	{
		if (argv[i][0] == '-' && !options->file_count)
		{
			if (ft_strncmp(argv[i], "-n", 2) == 0)
				parse_n_option(argv, &i, options);
			else if (ft_strncmp(argv[i], "-b", 2) == 0)
				//parse_b_option(argv, &i, options);
				;
		}
		else
			parse_filenames(argv, &i, options);
		i++;
	}
}
