/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:39:33 by kei               #+#    #+#             */
/*   Updated: 2023/09/13 17:29:30 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_tail(int argc, char **argv)
{
	t_options	options;

	options.n = 10;
	options.file_count = 0;
	options.option_count = 0;
	options.plus_flag = 0;
	options.n_flag = 0;
	options.b_flag = 0;
	options.c_flag = 0;
	if (!parse_options(argc, argv, &options))
		return ;
	execute_tail(&options);
	free(options.filenames);
}

void	execute_tail(t_options *options)
{
	int	i;

	i = 0;
	while (i < options->file_count)
	{
		if (options->n_flag)
			display_n_option(options, i);
		else
			display_n_option(options, i);
		i++;
		if (!(i == options->file_count))
			write(1, "\n", 1);
	}
}
