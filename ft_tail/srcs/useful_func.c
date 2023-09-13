/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:01:25 by kei               #+#    #+#             */
/*   Updated: 2023/09/13 20:03:00 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	is_valid_number(char *num)
{
	if (num[0] == '+' || num[0] == '-')
		num++;
	while (*num)
	{
		if (!(*num >= '0' && *num <= '9'))
			return (0);
		num++;
	}
	return (1);
}

void	check_sign(char *num_part, t_options *options)
{
	if (num_part[0] == '+' || num_part[0] == '-')
	{
		options->n = ft_atoi(&num_part[1]);
		if (num_part[0] == '+')
			options->plus_flag = 1;
	}
	else
		options->n = ft_atoi(num_part);
}
