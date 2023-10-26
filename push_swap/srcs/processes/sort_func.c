/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:35:28 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/27 05:35:46 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_b_op(int op)
{
	if (op == 0)
		write(1, "sb\n", 3);
	if (op == 1)
		write(1, "rb\n", 3);
	if (op == 2)
		write(1, "rrb\n", 4);
}

static int	in_rev_order(t_stack *b)
{
	if (b->prev == b->next)
		return (0);
	b = b->next;
	while (!b->next->is_separator)
	{
		if (!(b->value > b->next->value))
			return (0);
		b = b->next;
	}
	return (1);
}

static int	execute(t_stack **a, t_stack **b, t_ms *ms, int op)
{
	static t_operation	f[] = {
		swap_b, rotate_b, rotate_rev_b
	};

	return (f[op](a, b, ms));
}

static int	execute_rev(t_stack **a, t_stack **b, t_ms *ms, int op)
{
	static t_operation	f[] = {
		swap_b, rotate_rev_b, rotate_b
	};

	return (f[op](a, b, ms));
}

void	sort_under_five(t_stack **a, t_stack **b, t_ms *ms, int count)
{
	int	op;

	if (count > ms->limit_count)
		return ;
	if (in_rev_order(*b) && ms->min_turn > count)
	{
		ms->min_turn = count;
		clear_operation(&ms->actual_op);
		copy_operation(ms, ms->op_list);
		return ;
	}
	op = -1;
	while (++op < 3)
	{
		if (ms->min_turn <= count)
			continue ;
		if (!execute(a, b, ms, op))
			continue ;
		ms->op = op;
		add_operation(&ms->op_list, op);
		sort_under_five(a, b, ms, count + 1);
		execute_rev(a, b, ms, op);
		delone_operation(&ms->op_list);
	}
}

void	quick_sort_b(t_stack **a, t_stack **b, t_ms *ms)
{
	sort_under_five(a, b, ms, 0);
	while (ms->actual_op)
	{
		print_b_op(ms->actual_op->op);
		execute(a, b, ms, ms->actual_op->op);
		ms->actual_op = ms->actual_op->next;
	}
	ms->actual_op = NULL;
	ms->op_list = NULL;
	ms->min_turn = 12;
	ms->op = 0;
	sorted_to_bottom(a, b, ms);
}
