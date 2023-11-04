/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:07:23 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/05 02:34:43 by kesawada         ###   ########.fr       */
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

int	rev_count(t_stack *b)
{
	int	max;
	int	count;

	max = 0;
	count = 0;
	while (!b->next->is_separator)
	{
		if (b->index - 1 == b->next->index)
		{
			count++;
			if (count > max)
				max = count;
			b = b->next;
			continue ;
		}
		b = b->next;
		count = 0;
	}
	return (max);
}

int	check_valid_operation(t_ms *ms, int operation)
{
	if (ms->op == SA && (operation == SA ||\
		operation == SS || operation == RA || operation == RR))
		return (0);
	if (ms->op == SB && (operation == SB ||\
		operation == SS || operation == RB || operation == RR))
		return (0);
	if (ms->op == SS && (operation == SS ||\
		operation == SA || operation == SB))
		return (0);
	if (ms->op == PA && operation == PB)
		return (0);
	if (ms->op == PB && operation == PA)
		return (0);
	if (ms->op == RA && (operation == RRA || operation == RR))
		return (0);
	if (ms->op == RB && (operation == RRB || operation == RR))
		return (0);
	if (ms->op == RR && (operation == RR ||
		operation == RA || operation == RB))
		return (0);
	if (ms->op == RRA && (operation == RA || operation == RRR))
		return (0);
	if (ms->op == RRB && (operation == RB || operation == RRR))
		return (0);
	if (ms->op == RRR && (operation == RRR ||
		operation == RRA || operation == RRB))
		return (0);
	return (1);
}

int	execute(t_stack **a, t_stack **b, t_ms *ms, int op)
{
	static t_operation f[] =
	{
		swap_a, push_b, rotate_a, rotate_rev_a, swap_b,\
		push_a, swap_ab, rotate_b,\
		rotate_ab, rotate_rev_b, rotate_rev_ab
	};

	return (f[op](a, b, ms));
}

int	execute_rev(t_stack **a, t_stack **b, t_ms *ms, int op)
{
	static t_operation f[] =
	{
		swap_a, push_a, rotate_rev_a, rotate_a, swap_b,\
		push_b, swap_ab, rotate_rev_b,\
		rotate_rev_ab, rotate_b, rotate_ab
	};

	return (f[op](a, b, ms));
}

int	get_min_pos(t_stack *a)
{
	int		count;

	count = 1;
	a = a->next;
	while (a->index == 0)
	{
		count++;
		a = a->next;
	}
	return (count);
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
		if (!is_qualified(*a, *b, ms, count) || !check_valid_operation(ms, op))
			continue ;
		if (!execute(a, b, ms, op))
			continue ;
		ms->op = op;
		add_operation(&ms->op_list, op);
		sort_under_six(a, b, ms, count + 1);
		execute_rev(a, b, ms, op);
		delone_operation(&ms->op_list);
	}
	ms->state = END;
}
