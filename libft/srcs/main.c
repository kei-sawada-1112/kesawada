/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:32:22 by kei               #+#    #+#             */
/*   Updated: 2023/09/15 13:06:03 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	str[] = "12ab";
	char	**endptr;

	endptr = (char **)malloc(sizeof(char *) * 100);
	printf("result: %ld\n", ft_strtol(str, endptr, 16));
}
