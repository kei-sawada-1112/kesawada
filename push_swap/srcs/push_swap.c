/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:35:37 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/25 00:25:14 by kesawada         ###   ########.fr       */
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
	ms = malloc(sizeof(t_ms));
	ms->count = 9;
	ms->op = INIT;
	init(a, b, size, argv);
	// swap_a(a, b, ms);
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
		ms->limit_count = 9;
		f[ms->state](a, b, ms, 0);
		return ;
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

	// a = a->next;
	// b = b->next;
	// while (a->next && !a->is_separator)
	// {
		// ft_printf("value: %d\n", a->value);
		// ft_printf("value: %d\n", a->next->value);
		// ft_printf("value: %d\n", a->next->next->value);
		// a = a->next;
	// }
	while (b->next && !b->is_separator)
	{
		ft_printf("b value: %d\n", b->value);
		b = b->next;
	}
	free(a);
	free(b);
}
