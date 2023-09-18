/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:32:22 by kei               #+#    #+#             */
/*   Updated: 2023/09/18 11:33:28 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_hexdump.h"
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write (1, "Usage: ", 7);
		write (1, argv[0], ft_strlen(argv[0]));
		write (1,  "<command> [<args>...]\n", 22);
		return (1);
	}
	if (ft_strcmp(argv[1], "hexdump") == 0)
		ft_hexdump(argc, argv);
	else
	{
		write (1, argv[1], ft_strlen(argv[1]));
		write (1, ": command not found\n", 20);
	}
	return (0);
}
