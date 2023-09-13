/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:22:31 by kei               #+#    #+#             */
/*   Updated: 2023/09/13 17:06:40 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Usage: %s <command> [<args>...]\n", argv[0]);
		return (1);
	}
	if (ft_strcmp(argv[1], "tail") == 0)
		ft_tail(argc, argv);
	else
		printf("%s: command not found\n", argv[1]);
	return (0);
}
