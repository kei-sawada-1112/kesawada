/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_16.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:11:01 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/10 20:13:51 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_descending(t_stack *start, int index)
{
	int		count;
	t_stack	*current;

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
			break ;
		current = current->next;
	}
	return (count);
}

void	simple_sort(t_stack **a, t_stack **b, t_ms *ms)
{
	t_stack	*current;
	int		index;
	int		count;
	int		next_count;
	int		push_count;

	index = 0;
	push_count = 0;
	set_index_to_value(*b);
	current = (*b)->next;
	while (*b != (*b)->next)
	{
		if (current->index == index)
		{
			next_count = count_descending(*b, index);
			count = next_count;
			while (1)
			{
				current = (*b)->next;
				if (current->index == index + next_count)
				{
					push_count += execute_and_write(a, b, ms, PA);
					if (next_count == 0)
						break ;
					next_count--;
				}
				else
				{
					if (!next_count && get_current_pos(*b, index) > ft_stacksize(*b) / 2 + 1)
						execute_and_write(a, b, ms, RRB);
					else
						execute_and_write(a, b, ms, RB);
				}
			}
			while (count + 1 > 0)
			{
				next_count = count_descending(*b, push_count);
				if ((*b)->next->index != push_count + next_count)
					execute_and_write(a, b, ms, RR);
				else
					execute_and_write(a, b, ms, RA);
				index++;
				count--;
			}
			current = (*b)->next;
		}
		else
			current = current->next;
	}
	set_index_to_value(*a);
	if (in_order(*a))
		ms->state = END;
	else if (ms->trans_list)
		ms->state = BACK_TO_B;
	else
		ms->state = SEND_UNDER_HALF;
}
