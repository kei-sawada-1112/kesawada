/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:35:37 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/25 13:28:16 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*print_op(int op)
{
	if (op == SA)
		return ("sa");
	if (op == SB)
		return ("sb");
	if (op == SS)
		return ("ss");
	if (op == PA)
		return ("pa");
	if (op == PB)
		return ("pb");
	if (op == RA)
		return ("ra");
	if (op == RB)
		return ("rb");
	if (op == RRA)
		return ("rra");
	if (op == RRB)
		return ("rrb");
	if (op == RRR)
		return ("rrr");
	else
		return (NULL);
}

static void	push_swap(t_stack **a, t_stack **b, int size, char **argv)
{
	t_ms	*ms;
	size_t	len;
	t_stack	*tmp;

	len = 0;
	static	t_push_swap_process f[] =
	{
		sort_under_six, send_a_to_b,
	};
	static t_operation func[] =
	{
		swap_a, swap_b, swap_ab, push_a, push_b,\
		rotate_a, rotate_b, rotate_ab,\
		rotate_rev_a, rotate_rev_b, rotate_rev_ab
	};
	ms = malloc(sizeof(t_ms));
	ms->op = INIT;
	ms->push_count = 0;
	ms->count = 0;
	init(a, b, size, argv);
	tmp = *a;
	if (size == 2)
	{
		while (!tmp->next->is_separator)
		{
			tmp = tmp->next;
			len++;
		}
		size = len;
	}
	if (size <= 7)
	{
		ms->state = UNDER_SIX;
		ms->limit_count = 12;
		ms->count = 12;
		size = 0;
	}
	else
		ms->state = A_TO_B;
	ms->op_list = NULL;
	ms->actual_op = NULL;
	while (ms->state != END)
		f[ms->state](a, b, ms, size);
	while (ms->actual_op)
	{
		ft_printf("%s\n", print_op(ms->actual_op->op));
		func[ms->actual_op->op](a, b, ms);
		ms->actual_op = ms->actual_op->next;
	}
	free(ms->actual_op);
	free(ms->op_list);
	free(ms);
	// }
	// else
	// 	ms->state = A_TO_B;
	// while (ms->state != END)
	// 	f[ms->state](a, b, ms, size);
	// ft_printf("count: %d\n", ms->count);
	// swap_top(a, b);
	// rotate(a, b);
	// rotate_rev(a, b);
	// push(a, b);
	// push(b, a);
	// push(b, a);
}

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	push_swap(&a, &b, argc, argv);
	a = a->next;
	b = b->next;
	while (a->next && !a->is_separator)
	{
		// ft_printf("index: %d\n", a->index);
		ft_printf("%d\n", a->value);
		// ft_printf("value: %d\n", a->next->value);
		// ft_printf("value: %d\n", a->next->next->value);
		// ft_printf("*-----------*\n");
		a = a->next;
	}
	while (b->next && !b->is_separator)
	{
		ft_printf("b  %d\n", b->value);
		b = b->next;
	}
	free(a);
	free(b);
}
