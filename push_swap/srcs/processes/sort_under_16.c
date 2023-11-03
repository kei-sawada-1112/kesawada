/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_16.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:11:01 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/03 17:56:01 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_consecutive(t_stack *start, int index)
{
	int		count;
	t_stack *current;

	count = 0;
	current = start->next;
	while (!current->is_separator)
	{
		if (current->index == index + count + 1)
		{
			count++;
			current = start;
		}
		else if (current->index == index + count)
			break;
		current = current->next;
	}
	return (count);
}
