/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:53:05 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/26 17:33:28 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	get_median(t_stack *stack, int size)
// {
// 	int		index;
// 	int		min;
// 	t_stack	*first;
// 	t_stack	*current;

// 	index = 0;
// 	first = stack->next;
// 	current = first;
// 	while (index < size)
// 	{
// 		if (current > )
// 	}
// }

void set_index_to_value(t_stack *stack)
{
	t_stack	*current;
	t_stack	*checker;
	int		count;

	current = stack->next;
	while (!current->is_separator)
	{
		count = 0;
		checker = stack->next;
		while (!checker->is_separator)
		{
			if (current->value > checker->value)
				count++;
			checker = checker->next;
		}
		current->index = count;
		current = current->next;
	}
}
