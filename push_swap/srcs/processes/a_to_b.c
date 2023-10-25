/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:49:07 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/25 12:49:02 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_a_to_b(t_stack **a, t_stack **b, t_ms *ms, int size)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = (*a)->next;
	while (count < size / 2)
	{
		if (current->index <= size / 2)
		{
			if (current->pos > size / 2)
			{
				while (!current->prev->is_separator)
					count += rotate_rev_a(a, NULL, ms);
			}
			else
			{
				while (!current->prev->is_separator)
					count += rotate_a(a, NULL, ms);
			}
			current = current->next;
			count += push_b(a, b, ms);
		}
		else
			current = current->next;
	}
	ms->count += count;
	ms->state = END;
}
