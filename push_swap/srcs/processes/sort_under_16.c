/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_16.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:11:01 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/10 21:03:39 by kesawada         ###   ########.fr       */
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

static int	push_and_rotate_b(t_stack **a, t_stack **b, int index)
{
	int		next_count;
	t_stack	*current;
	int		push_count;

	next_count = count_descending(*b, index);
	push_count = 0;
	while (1)
	{
		current = (*b)->next;
		if (current->index == index + next_count)
		{
			push_count += execute_and_write(a, b, PA);
			if (next_count == 0)
				return (push_count);
			next_count--;
		}
		else
		{
			if (!next_count && get_current_pos(*b, index) > \
				ft_stacksize(*b) / 2 + 1)
				execute_and_write(a, b, RRB);
			else
				execute_and_write(a, b, RB);
		}
	}
}

static void	set_state_simple(t_stack *a, t_ms *ms)
{
	if (in_order(a))
		ms->state = END;
	else if (ms->trans_list)
		ms->state = BACK_TO_B;
	else
		ms->state = SEND_UNDER_HALF;
}

static void	index_based_sort(t_stack **a, t_stack **b, \
	int *index, int *push_count)
{
	t_stack	*current;
	int		count;
	int		next_count;

	current = (*b)->next;
	while (*b != (*b)->next)
	{
		if (current->index == *index)
		{
			count = count_descending(*b, *index);
			*push_count += push_and_rotate_b(a, b, *index);
			while (count-- + 1 > 0)
			{
				next_count = count_descending(*b, *push_count);
				if ((*b)->next->index != *push_count + next_count)
					execute_and_write(a, b, RR);
				else
					execute_and_write(a, b, RA);
				(*index)++;
			}
			current = (*b)->next;
		}
		else
			current = current->next;
	}
}

void	simple_sort(t_stack **a, t_stack **b, t_ms *ms)
{
	int		index;
	int		push_count;

	index = 0;
	push_count = 0;
	set_index_to_value(*b);
	index_based_sort(a, b, &index, &push_count);
	set_state_simple(*a, ms);
}
