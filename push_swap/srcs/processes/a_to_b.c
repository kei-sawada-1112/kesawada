/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:49:07 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/25 13:29:48 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_a_to_b(t_stack **a, t_stack **b, t_ms *ms, int size)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = (*a)->next;
	while (ms->push_count < size / 2)
	{
		if (current->index < size / 2)
		{
			if (current->pos > size / 2)
			{
				while (!current->prev->is_separator)
					// count += rotate_rev_a(a, NULL, ms);
					count += rotate_rev_a(a, NULL, ms);
			}
			else
			{
				while (!current->prev->is_separator)
					count += rotate_a(a, NULL, ms);
			}
			current = current->next;
			ms->push_count += push_b(a, b, ms);
			count += 1;
		}
		else
			current = current->next;
	}
	ms->count += count;
	ms->state = END;
}
