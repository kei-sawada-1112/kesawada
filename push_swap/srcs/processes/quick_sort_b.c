/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:07:23 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/25 10:19:58 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_order(t_stack *a)
{
	if (a->prev == a->next)
		return (0);
	a = a->next;
	while (!a->next->is_separator)
	{
		if (!(a->value < a->next->value))
			return (0);
		a = a->next;
	}
	return (1);
}

int	check_valid_operation(t_ms *ms, int operation)
{
	if (ms->op == SA && (operation == SA ||\
		operation == SS))
		return (0);
	if (ms->op == SB && (operation == SB ||\
		operation == SS))
		return (0);
	if (ms->op == SS && (operation == SS ||\
		operation == SA || operation == SB))
		return (0);
	if (ms->op == PA && operation == PB)
		return (0);
	if (ms->op == PB && operation == PA)
		return (0);
	if (ms->op == RA && operation == RRA)
		return (0);
	if (ms->op == RB && operation == RRB)
		return (0);
	if (ms->op == RR && (operation == RR ||
		operation == RA || operation == RB))
		return (0);
	if (ms->op == RRA && operation == RA)
		return (0);
	if (ms->op == RRB && operation == RB)
		return (0);
	if (ms->op == RRR && (operation == RRR ||
		operation == RRA || operation == RRB))
		return (0);
	return (1);
}

void	sort_under_six(t_stack **a, t_stack **b, t_ms *ms, int count)
{
	int			op;

	static t_operation f[] =
	{
		swap_a, swap_b, swap_ab, push_a, push_b,\
		rotate_a, rotate_b, rotate_ab,\
		rotate_rev_a, rotate_rev_b, rotate_rev_ab
	};
	static t_operation f_rev[] =
	{
		swap_a, swap_b, swap_ab, push_b, push_a,\
		rotate_rev_a, rotate_rev_b, rotate_rev_ab,\
		rotate_a, rotate_b, rotate_ab
	};
	if (count > ms->limit_count)
		return ;
	if (((*b)->next->is_separator) && in_order(*a))
	{
		if (ms->count > count)
		{
			(*a) = (*a)->next;
			while ((*a)->next && !(*a)->is_separator)
			{
				// ft_printf("index: %d\n", a->index);
				ft_printf("value: %d\n", (*a)->value);
				// ft_printf("value: %d\n", a->next->value);
				// ft_printf("value: %d\n", a->next->next->value);
				// ft_printf("*-----------*\n");
				(*a) = (*a)->next;
			}
			ms->count = count;
			// while (ms->op_list)
			// {
			// 	ft_printf("------op_list: %d\n------\n", ms->op_list->op);
			// 	ms->op_list = ms->op_list->next;
			// }
			clear_operation(&ms->actual_op);
			copy_operation(ms, ms->op_list);
		}
		return ;
	}
	op = -1;
	while (++op < 11)
	{
		if (!check_valid_operation(ms, op) || ms->count <= count)
			continue ;
		if (!f[op](a, b, ms))
			continue ;
		ms->op = op;
		add_operation(&ms->op_list, op);
		sort_under_six(a, b, ms, count + 1);
		f_rev[op](a, b, ms);
		delone_operation(&ms->op_list);
	}
}

// int	quick_sort_b(t_stack **a, t_stack **b, t_ms *ms, int count)
// {
// 	int	operation;

// 	static t_operation f[] =
// 	{
// 		swap_a, swap_b, swap_ab, push_a, push_b,
// 		rotate_a, rotate_b, rotate_rev_a, rotate_rev_b,
// 		rotate_rev_ab
// 	};
// 	if (in_order(*b))
// 		return (count);


// }
