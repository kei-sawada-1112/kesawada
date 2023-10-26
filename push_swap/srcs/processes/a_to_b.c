/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:49:07 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/27 05:17:36 by kesawada         ###   ########.fr       */
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

void	send_big_to_b(t_stack **a, t_stack **b, t_ms *ms)
{
	int		i;
	int		size;

	set_index_to_value(*a);
	size = sorted_count(*a);
	i = ft_stacksize(*a) - size;
	// if (i == 1)
	// {
	// 	ms->count += rotate_a(a, b, ms);
	// 	print_op(RA);
	// 	ms->state = END;
	// 	return ;
	// }
	while (i > 0)
	{
		ms->count += push_b(a, b, ms);
		print_op(PB);
		(*b)->next->pos = --i;
	}
	ms->state = B_TO_A;
}

void	send_a_to_b(t_stack **a, t_stack **b, t_ms *ms)
{
	t_stack	*current;
	int		i;
	int		half_size;

	half_size = ft_stacksize(*a) / 2 + ft_stacksize(*a) % 2;
	i = half_size;
	current = (*a)->next;
	while (i > 0)
	{
		if (current->index < half_size)
		{
			if (current->pos > half_size)
			{
				while (!current->prev->is_separator)
				{
					ms->count += rotate_rev_a(a, NULL, ms);
					print_op(RRA);
				}
			}
			else
			{
				while (!current->prev->is_separator)
				{
					ms->count += rotate_a(a, NULL, ms);
					print_op(RA);
				}
			}
			ms->count += push_b(a, b, ms);
			current = (*a)->next;
			print_op(PB);
			(*b)->next->pos = --i;
		}
		else
			current = current->next;
	}
	// {
	//  ms->state = END;
	//  return ;
	// }
	send_b_to_a(a, b, ms);
}

void	send_b_to_a(t_stack **a, t_stack **b, t_ms *ms)
{
	t_stack	*current;
	int		i;
	int		half_size;
	int		push_count;

	set_index_to_value(*b);
	half_size = ft_stacksize(*b) / 2 - !(ft_stacksize(*b) % 2);
	i = ft_stacksize(*b) / 2;
	current = (*b)->next;
	push_count = 0;
	while (i > 0)
	{
		if (current->index > half_size)
		{
			if (current->pos < half_size)
			{
				while (!current->prev->is_separator)
				{
					ms->count += rotate_rev_b(NULL, b, ms);
					print_op(RRB);
				}
			}
			else
			{
				while (!current->prev->is_separator)
				{
					ms->count += rotate_b(NULL, b, ms);
					print_op(RB);
				}
			}
			push_count += push_a(a, b, ms);
			current = (*b)->next;
			print_op(PA);
			(*a)->next->pos = --i;
		}
		else
			current = current->next;
	}
	ms->count += push_count;
	add_trans_list(&ms->trans_list, push_count);
	if (ft_stacksize(*b) <= 4)
		ms->state = QUICK_SORT_B;
	else
		send_b_to_a(a, b, ms);
}
