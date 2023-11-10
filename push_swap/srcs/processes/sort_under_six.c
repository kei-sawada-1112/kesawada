/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:07:23 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/10 20:57:34 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	rev_count(t_stack *b)
// {
// 	int	max;
// 	int	count;

// 	max = 0;
// 	count = 0;
// 	while (!b->next->is_separator)
// 	{
// 		if (b->index - 1 == b->next->index)
// 		{
// 			count++;
// 			if (count > max)
// 				max = count;
// 			b = b->next;
// 			continue ;
// 		}
// 		b = b->next;
// 		count = 0;
// 	}
// 	return (max);
// }

int	is_valid_op(t_stack *a, t_ms *ms, int op)
{
	if (a->next->index < a->next->next->index && \
		(op == SA || op == SS || op == RA || op == RRA))
		return (0);
	if ((ms->op == SA && (op == SA || op == SS || op == RA || op == RR)) \
		|| (ms->op == SB && (op == SB || op == SS || op == RB || op == RR)) \
		|| (ms->op == SS && (op == SS || op == SA || op == SB)) \
		|| (ms->op == PA && op == PB) || (ms->op == PB && op == PA) \
		|| (ms->op == RA && (op == RRA || op == RR)) \
		|| (ms->op == RB && (op == RRB || op == RR)) \
		|| (ms->op == RR && (op == RR || op == RA || op == RB)) \
		|| (ms->op == RRA && (op == RA || op == RRR)) \
		|| (ms->op == RRB && (op == RB || op == RRR)) \
		|| (ms->op == RRR && (op == RRR || op == RRA || op == RRB)))
		return (0);
	return (1);
}

int	execute(t_stack **a, t_stack **b, int op)
{
	static t_operation	f[] = \
	{
		swap_a, push_b, rotate_a, rotate_rev_a, swap_b, \
		push_a, swap_ab, rotate_b, \
		rotate_ab, rotate_rev_b, rotate_rev_ab
	};

	return (f[op](a, b));
}

int	execute_rev(t_stack **a, t_stack **b, int op)
{
	static t_operation	f[] = \
	{
		swap_a, push_a, rotate_rev_a, rotate_a, swap_b, \
		push_b, swap_ab, rotate_rev_b, \
		rotate_rev_ab, rotate_b, rotate_ab
	};

	return (f[op](a, b));
}

int	is_qualified(t_stack *a, t_stack *b, t_ms *ms, int count)
{
	if (ft_stacksize(b) + count + get_min_pos(a) + 1 >= ms->min_turn)
		return (0);
	return (1);
}

void	sort_under_six(t_stack **a, t_stack **b, t_ms *ms, int count)
{
	int	op;

	if (count > ms->limit_count)
		return ;
	if (((*b) == (*b)->next && in_order(*a)) && ms->min_turn > count)
	{
		ms->min_turn = count;
		clear_operation(&ms->actual_op);
		copy_operation(ms, ms->op_list);
		return ;
	}
	op = -1;
	while (++op < 11)
	{
		if (!is_qualified(*a, *b, ms, count) || !is_valid_op(*a, ms, op))
			continue ;
		if (!execute(a, b, op))
			continue ;
		ms->op = op;
		add_operation(&ms->op_list, op);
		sort_under_six(a, b, ms, count + 1);
		execute_rev(a, b, op);
		delone_operation(&ms->op_list);
	}
	ms->state = END;
}
