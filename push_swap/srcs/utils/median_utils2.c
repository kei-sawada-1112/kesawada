/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:53:05 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/24 13:27:35 by kesawada         ###   ########.fr       */
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

void	set_index_to_value(t_stack *stack, int *array, int argc)
{
	int		j;
	int		min;
	int		index;
	int		count;
	t_stack	*first;

	index = 0;
	count = 0;
	min = INT_MAX;
	first = stack;
	while (count < argc - 1)
	{
		j = 1;
		while (j < argc)
		{
			if (min > array[j])
			{
				min = array[j];
				index = j;
			}
			j++;
		}
		min = INT_MAX;
		array[index] = INT_MAX;
		j = 0;
		while (j < index)
		{
			stack = stack->next;
			j++;
		}
		stack->index = count;
		stack = first;
		count++;
	}
}
