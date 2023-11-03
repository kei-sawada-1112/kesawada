/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:49:07 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/03 17:56:57 by kesawada         ###   ########.fr       */
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

static int	get_current_pos(t_stack *b, int index)
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

// int	is_ascending(t_stack *b)
// {
// 	t_stack	*current;

// 	current = b->next;
// 	while (!current->next->is_separator)
// 	{
// 		if (current->index > current->next->index)
// 			return (0);
// 		current = current->next;
// 	}
// 	return (1);
// }

// int	is_discending(t_stack *b)
// {
// 	t_stack	*current;

// 	current = b->next;
// 	while (!current->next->is_separator)
// 	{
// 		if (current->index < current->next->index)
// 			return (0);
// 		current = current->next;
// 	}
// 	return (1);
// }

void	send_under_half(t_stack **a, t_stack **b, t_ms *ms)
{
	int		i;
	int		index;
	int		size;
	int		sorted;
	t_stack	*current;
	int		next_count;

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
				next_count = count_consecutive(*b, sorted);
				if ((*b)->next->index != sorted + next_count)
				{
					rotate_ab(a, b, ms);
					print_op(RR);
				}
				else
				{
					rotate_a(a, b, ms);
					print_op(RA);
				}
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
			push_b(a, b, ms);
			print_op(PB);
		}
		else
		{
			next_count = count_consecutive(*b, sorted);
			if (next_count && (*b)->next->index != sorted + next_count)
			{
				rotate_ab(a, b, ms);
				print_op(RR);
			}
			else
			{
				rotate_a(a, NULL, ms);
				print_op(RA);
			}
		}
		current = (*a)->next;
		if (ft_stacksize(*b) == size / 2)
		{
			i--;
			break ;
		}
	}
	while (++i < size / 2 + size % 2)
	{
		next_count = count_consecutive(*b, sorted);
		if (!next_count && get_current_pos(*b, sorted) > ft_stacksize(*b) / 2)
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
	if (ft_stacksize(*b) <= 16)
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
	set_index_to_value(*a);
	while (i > 0)
	{
		if (current->index < half_size)
		{
			// if ((*b)->next->index < 25)
			// {
			// 	rotate_b(a, b, ms);
			// 	print_op(RB);
			// }
			push_b(a, b, ms);
			print_op(PB);
			--i;
		}
		else
		{
			if ((*b)->next->index < 25)
			{
				rotate_ab(a, b, ms);
				print_op(RR);
			}
			else
			{
				rotate_a(a, NULL, ms);
				print_op(RA);
			}
		}
		current = (*a)->next;
	}
	ms->state = B_TO_A;
}

void simple_sort(t_stack **a, t_stack **b, t_ms *ms)
{
	t_stack *current;
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
			next_count = count_consecutive(*b, index);
			count = next_count;
			while (1)
			{
				current = (*b)->next;
				if (current->index == index + next_count)
				{
					push_count += push_a(a, b, ms);
					print_op(PA);
					if (next_count == 0)
						break ;
					next_count--;
				}
				else
				{
					if (!next_count && get_current_pos(*b, index) > ft_stacksize(*b) / 2 + 1)
					{
						rotate_rev_b(a, b, ms);
						print_op(RRB);
					}
					else
					{
						rotate_b(a, b, ms);
						print_op(RB);
					}
				}
			}
			while (count + 1 > 0)
			{
				next_count = count_consecutive(*b, push_count);
				if ((*b)->next->index != push_count + next_count)
				{
					rotate_ab(a, b, ms);
					print_op(RR);
				}
				else
				{
					rotate_a(a, b, ms);
					print_op(RA);
				}
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
		ms->state = A_TO_B_NEXT;
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
			next_count = count_consecutive(*b, sorted);
			if ((*b)->next->index != sorted + next_count)
			{
				rotate_ab(a, b, ms);
				print_op(RR);
			}
			else
			{
				rotate_a(a, b, ms);
				print_op(RA);
			}
			sorted++;
		}
		else
		{
			push_b(a, b, ms);
			print_op(PB);
		}
	}
	delone_trans_list(&ms->trans_list);
	if (ft_stacksize(*b) <= 16)
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
				--i;
			}
			else
			{
				rotate_b(NULL, b, ms);
				print_op(RB);
			}
			current = (*b)->next;
		}
		add_trans_list(&ms->trans_list, push_count);
		if (ft_stacksize(*b) <= 16)
			ms->state = SIMPLE_SORT;
	}
}
