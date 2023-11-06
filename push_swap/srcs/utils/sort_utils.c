/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:57:01 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/06 10:30:23 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_count(t_stack *a)
{
	int	max;
	int	count;

	max = 0;
	count = 1;
	while (!a->next->is_separator)
	{
		if (a->index + 1 == a->next->index)
		{
			count++;
			if (count > max)
				max = count;
			a = a->next;
			continue ;
		}
		a = a->next;
		count = 1;
	}
	return (max);
}

int	get_current_pos(t_stack *b, int index)
{
	t_stack	*current;
	int		pos;

	current = b->next;
	pos = 1;
	while (1)
	{
		if (current->index == index)
			return (pos);
		current = current->next;
		pos++;
	}
}

