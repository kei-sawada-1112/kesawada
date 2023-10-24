/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:07:23 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/25 01:16:42 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_order(t_stack *a)
{
	if (a->value == a->next->value)
		return (0);
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
	int	operation;

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
		*a = (*a)->next;
		ft_printf("------conguraturations------\n");
		while ((*a)->next && !(*a)->is_separator)
		{
			ft_printf("value: %d\n", (*a)->value);
			(*a) = (*a)->next;
		}
		ms->count = count;
		return ;
	}
	operation = -1;
	while (++operation < 11)
	{
		if (!check_valid_operation(ms, operation) || ms->count <= count)
			continue ;
		// ft_printf("pre ope: %d\n", operation);
		// ft_printf("count: %d\n", count);
		// ft_printf("value: %d\n", (*a)->value);
		// if (operation == 4)
		// {
		// ft_printf("---------------\n");
		// ft_printf("value: %d\n", (*a)->next->value);
		// ft_printf("value: %d\n", (*a)->next->next->value);
		// ft_printf("value: %d\n", (*a)->next->next->next->value);
		// ft_printf("---------------\n");
		// }
		// ft_printf("value: %d\n", (*a)->next->next->next->next->value);
		// ft_printf("b value: %d\n", (*b)->value);

		// (*a) = (*a)->next;
		// }
		if (!f[operation](a, b, ms))
			continue ;
		ms->op = operation;
		sort_under_six(a, b, ms, count + 1);
		f_rev[operation](a, b, ms);
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
