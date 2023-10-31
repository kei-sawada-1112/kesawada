/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:49:07 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/31 23:29:36 by kesawada         ###   ########.fr       */
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

int	is_ascending(t_stack *b)
{
	t_stack	*current;

	current = b->next;
	while (!current->next->is_separator)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_discending(t_stack *b)
{
	t_stack	*current;

	current = b->next;
	while (!current->next->is_separator)
	{
		if (current->index < current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

void	send_under_half(t_stack **a, t_stack **b, t_ms *ms)
{
	int		i;
	int		index;
	int		size;
	int		sorted;
	t_stack	*current;

	set_index_to_value(*a);
	sorted = sorted_count(*a);
	size = ft_stacksize(*a) - sorted;
	index = (ft_stacksize(*a) + sorted_count(*a)) / 2;
	current = (*a)->next;
	i = size;
	if (i < 16)
	{
		while (i-- > 0)
		{
			if ((*a)->next->index == sorted)
			{
				rotate_a(a, b, ms);
				print_op(RA);
				sorted++;
			}
			else
			{
				push_b(a, b, ms);
				print_op(PB);
			}
		}
		ms->state = SIMPLE_SORT;
		return ;
	}
	while (i-- > 0)
	{
		if (current->index < index)
		{
			ms->count += push_b(a, b, ms);
			print_op(PB);
		}
		else
		{
			if (!(is_ascending(*b)) && (*b)->next->index != sorted)
			{
				ms->count = rotate_ab(a, b, ms);
				print_op(RR);
			}
			else
			{	ms->count += rotate_a(a, NULL, ms);
				print_op(RA);
			}
		}
		current = (*a)->next;
	}
	while (++i < size / 2 + size % 2)
	{
		if (!is_discending(*b) && (*b)->next->index != sorted)
		{
			rotate_rev_ab(a, b, ms);
			print_op(RRR);
		}
		else
		{
			rotate_rev_a(a, NULL, ms);
			print_op(RRA);
		}
	}
	if (ft_stacksize(*b) < 16)
		ms->state = SIMPLE_SORT;
	else
		ms->state = B_TO_A;
}

void	send_a_to_b(t_stack **a, t_stack **b, t_ms *ms)
{
	int		i;
	int		half_size;
	t_stack	*current;

	half_size = ft_stacksize(*a) / 2 + ft_stacksize(*a) % 2;
	i = half_size;
	current = (*a)->next;
	while (i > 0)
	{
		if (current->index < half_size)
		{
			ms->count += push_b(a, b, ms);
			print_op(PB);
			(*b)->next->pos = --i;
		}
		else
		{
			ms->count += rotate_a(a, NULL, ms);
			print_op(RA);
		}
		current = (*a)->next;
	}
	ms->state = B_TO_A;
}

void send_under_16(t_stack **a, t_stack **b, t_ms *ms, int pos)
{
	while (pos--)
	{
		rotate_b(a, b, ms);
		print_op(RB);
	}
	push_a(a, b, ms);
	print_op(PA);
	rotate_a(a, b, ms);
	print_op(RA);
}

int	check_direction(t_stack *b, int index)
{
	t_stack	*current;

	current = b->next;
	while (current != current->next)
	{
		if (current->index == index + 1)
			return (1);
		else if (current->index == index)
			return (0);
		current = current->next;
	}
	return (1);
}

void simple_sort(t_stack **a, t_stack **b, t_ms *ms)
{
	t_stack *current;
	int		index;
	int		pos;
	int		count;
	int		next_count;
	int		prev_count;

	index = 0;
	pos = 1;
	set_index_to_value(*b);
	current = (*b)->next;
		set_index_to_value(*b);
	current = (*b)->next;
	while (*b != (*b)->next)
	{
		if (current->index == index)
		{
			next_count = count_consecutive(*b, index, 1);
			prev_count = count_consecutive(*b, index, 0);
			if (next_count >= prev_count)
			{
				count = next_count;
				while (pos--)
				{
					current = (*b)->next;
					if (current->index == index + next_count)
					{
						push_a(a, b, ms);
						print_op(PA);
						next_count--;
					}
					else
					{
						rotate_b(a, b, ms);
						print_op(RB);
					}
				}
			}
			else
			{
				count = prev_count;
				while (pos++ != ft_stacksize(*b))
				{
					current = (*b)->prev;
					if (current->index == index + prev_count)
					{
						push_a(a, b, ms);
						print_op(PA);
						prev_count--;
					}
					else
					{
						rotate_rev_b(a, b, ms);
						print_op(RB);
					}
				}
			}
			while (count + 1 > 0)
			{
				rotate_a(a, b, ms);
				print_op(RA);
				index++;
				count--;
			}
			pos = 1;
			current = (*b)->next;
		}
		else
		{
			current = current->next;
			pos++;
		}
	}
	// if (sorted_count(*a) > 20)
	// 	ms->state = END;
	set_index_to_value(*a);
	if (in_order(*a))
		ms->state = END;
	else if (ms->trans_list)
		ms->state = BACK_TO_B;
	else
		ms->state = A_TO_B_NEXT;
}

void	back_to_b(t_stack **a, t_stack **b, t_ms *ms)
{
	int	sorted;

	set_index_to_value(*a);
	sorted = sorted_count(*a);
	while (ms->trans_list->count--)
	{
		if ((*a)->next->index == sorted)
		{
			ms->count += rotate_a(a, b, ms);
			print_op(RA);
			sorted++;
		}
		else
		{
			ms->count += push_b(a, b, ms);
			print_op(PB);
		}
	}
	delone_trans_list(&ms->trans_list);
	if (ft_stacksize(*b) < 16)
		ms->state = SIMPLE_SORT;
	else
	 	ms->state = B_TO_A;
}

void	send_b_to_a(t_stack **a, t_stack **b, t_ms *ms)
{
	int		i;
	int		half_size;
	int		push_count;
	t_stack	*current;

	// if (ft_stacksize(*b) <= 4)
	// 	ms->state = QUICK_SORT_B;
	if (ft_stacksize(*b) <= 16)
		ms->state = SIMPLE_SORT;
	else
	{
		set_index_to_value(*b);
		half_size = ft_stacksize(*b) / 2 - !(ft_stacksize(*b) % 2);
		i = ft_stacksize(*b) / 2;
		push_count = 0;
		current = (*b)->next;
		while (i > 0)
		{
			if (current->index > half_size)
			{
				push_count += push_a(a, b, ms);
				print_op(PA);
				(*a)->next->pos = --i;
			}
			else
			{
				ms->count += rotate_b(NULL, b, ms);
				print_op(RB);
			}
			current = (*b)->next;
		}
		ms->count += push_count;
		add_trans_list(&ms->trans_list, push_count);
		if (ft_stacksize(*b) <= 16)
			ms->state = SIMPLE_SORT;
	}
}
