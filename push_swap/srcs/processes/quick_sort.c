/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:24:37 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/10 20:15:54 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	send_under_16(t_stack **a, t_stack **b, t_ms *ms, int i)
{
	int	next_count;
	int	sorted;

	sorted = sorted_count(*a);
	while (i-- > 0)
	{
		if ((*a)->next->index == sorted)
		{
			next_count = count_descending(*b, sorted);
			if ((*b)->next->index != sorted + next_count)
				execute_and_write(a, b, ms, RR);
			else
				execute_and_write(a, b, ms, RA);
			sorted++;
		}
		else
			execute_and_write(a, b, ms, PB);
	}
	ms->state = SIMPLE_SORT;
	return ;
}

void	send_under_half(t_stack **a, t_stack **b, t_ms *ms)
{
	int	i;
	int	size;
	int	sorted;
	int	next_count;

	set_index_to_value(*a);
	sorted = sorted_count(*a);
	size = ft_stacksize(*a) - sorted;
	i = ft_stacksize(*a) - sorted_count(*a);
	if (i < 16)
	{
		send_under_16(a, b, ms, i);
		return ;
	}
	push_b_and_rotate(a, b, ms, &i);
	while (i++ < size / 2 + size % 2)
	{
		next_count = count_descending(*b, sorted);
		if (!next_count && get_current_pos(*b, sorted) > ft_stacksize(*b) / 2)
			execute_and_write(a, b, ms, RRR);
		else
			execute_and_write(a, b, ms, RRA);
	}
	set_state(*b, ms, 16);
}

void	send_a_to_b(t_stack **a, t_stack **b, t_ms *ms)
{
	int		i;
	int		half_size;
	t_stack	*current;

	half_size = ft_stacksize(*a) / 2 + ft_stacksize(*a) % 2;
	i = half_size;
	current = (*a)->next;
	set_index_to_value(*a);
	while (i > 0)
	{
		if (current->index < half_size)
		{
			execute_and_write(a, b, ms, PB);
			--i;
		}
		else
		{
			if ((*b)->next->index < 25)
				execute_and_write(a, b, ms, RR);
			else
				execute_and_write(a, b, ms, RA);
		}
		current = (*a)->next;
	}
	set_state(*b, ms, 16);
}

void	back_to_b(t_stack **a, t_stack **b, t_ms *ms)
{
	int	sorted;
	int	next_count;

	set_index_to_value(*a);
	sorted = sorted_count(*a);
	while (ms->trans_list->count--)
	{
		if ((*a)->next->index == sorted)
		{
			next_count = count_descending(*b, sorted);
			if ((*b)->next->index != sorted + next_count)
				execute_and_write(a, b, ms, RR);
			else
				execute_and_write(a, b, ms, RA);
			sorted++;
		}
		else
			execute_and_write(a, b, ms, PB);
	}
	delone_trans_list(&ms->trans_list);
	set_state(*b, ms, 16);
}

void	send_b_to_a(t_stack **a, t_stack **b, t_ms *ms)
{
	int		i;
	int		size;
	int		half_size;
	int		push_count;
	t_stack	*current;

	size = ft_stacksize(*b);
	set_index_to_value(*b);
	half_size = size / 2 - !(size % 2);
	i = size / 2;
	push_count = 0;
	current = (*b)->next;
	while (i > 0)
	{
		if (current->index > half_size)
		{
			push_count += execute_and_write(a, b, ms, PA);
			--i;
		}
		else
			execute_and_write(a, b, ms, RB);
		current = (*b)->next;
	}
	add_trans_list(&ms->trans_list, push_count);
	set_state(*b, ms, 16);
}
