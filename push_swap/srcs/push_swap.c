/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:35:37 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/25 09:55:16 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack **a, t_stack **b, int size, char **argv)
{
	t_ms	*ms;

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
	init(a, b, size, argv);
	// swap_a(a, b, ms);
	// push_a(a, b, ms);
	// push_a(a, b, ms);
	// swap_a(a, b, ms);
	// push_a(a, b, ms);
	// rotate_rev_ab(a, b, ms);
	// push_a(a, b, ms);
	// push_b(a, b, ms);
	// rotate_a(a, b, ms);
	// if (size - 1 < 7)
	// {
		ms->state = UNDER_SIX;
		ms->limit_count = 12;
		ms->count = 12;
		ms->op_list = NULL;
		ms->actual_op = NULL;
		f[ms->state](a, b, ms, 0);
		ft_printf("count: %d\n", ms->count);
		while (ms->actual_op)
		{
			func[ms->actual_op->op](a, b, ms);
			ms->actual_op = ms->actual_op->next;
		}
		// b = b->next;
		// while (ms->actual_op)
		// {
		// 	// ft_printf("index: %d\n", (*a)->index);
		// 	ft_printf("enum: %d\n", ms->actual_op->op);
		// 	// ft_printf("value: %d\n", (*a)->next->value);
		// 	// ft_printf("value: %d\n", (*a)->next->next->value);
		// 	// ft_printf("*-----------*\n");
		// 	ms->actual_op = ms->actual_op->next;
		// }
		free(ms->actual_op);
		free(ms->op_list);
		free(ms);
		// return ;
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
	// b = b->next;
	while (a->next && !a->is_separator)
	{
		// ft_printf("index: %d\n", a->index);
		ft_printf("value: %d\n", a->value);
		// ft_printf("value: %d\n", a->next->value);
		// ft_printf("value: %d\n", a->next->next->value);
		// ft_printf("*-----------*\n");
		a = a->next;
	}
	// while (b->next && !b->is_separator)
	// {
	// 	ft_printf("b index: %d\n", b->index);
	// 	ft_printf("b value: %d\n", b->value);
	// 	ft_printf("b value: %d\n", b->next->value);
	// 	ft_printf("b value: %d\n", b->prev->value);
	// 	ft_printf("*-----------*\n");
	// 	b = b->next;
	// }
	free(a);
	free(b);
}
