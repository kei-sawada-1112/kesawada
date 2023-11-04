/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:35:37 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/05 01:48:28 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(int op)
{
	if (op == SA)
		write(1, "sa\n", 3);
	if (op == SB)
		write(1, "sb\n", 3);
	if (op == SS)
		write(1, "ss\n", 3);
	if (op == PA)
		write(1, "pa\n", 3);
	if (op == PB)
		write(1, "pb\n", 3);
	if (op == RA)
		write(1, "ra\n", 3);
	if (op == RB)
		write(1, "rb\n", 3);
	if (op == RR)
		write(1, "rr\n", 3);
	if (op == RRA)
		write(1, "rra\n", 4);
	if (op == RRB)
		write(1, "rrb\n", 4);
	if (op == RRR)
		write(1, "rrr\n", 4);
}

static void	handle_process(t_stack **a, t_stack **b, t_ms *ms)
{
	static	t_push_swap_process f[] =
	{
		send_a_to_b, send_b_to_a, quick_sort_b, \
		send_under_half, simple_sort, back_to_b,
	};

	f[ms->state](a, b, ms);
}

static t_ms	*init_ms()
{
	t_ms	*ms;

	ms = malloc(sizeof(t_ms));
	if (!ms)
		return (NULL);
	ms->op = INIT;
	ms->count = 0;
	ms->min_turn = 12;
	ms->limit_count = 12;
	ms->op_list = NULL;
	ms->actual_op = NULL;
	ms->trans_list = NULL;
	return (ms);
}

static void	push_swap(t_stack **a, t_stack **b, int size, char **argv)
{
	t_ms	*ms;
	size_t	len;
	t_stack	*tmp;

	len = 0;
	init(a, b, size, argv);
	ms = init_ms();
	set_index_to_value(*a);
	if (!ms)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	tmp = *a;
	if (size == 2)
	{
		while (!tmp->next->is_separator)
		{
			tmp = tmp->next;
			len++;
		}
		size = len + 1;
	}
	if (size <= 7)
	{
		sort_under_six(a, b, ms, 0);
		while (ms->actual_op)
		{
			print_op(ms->actual_op->op);
			ms->actual_op = ms->actual_op->next;
		}
	}
	else
		ms->state = A_TO_B;
	while (ms->state != END)
		handle_process(a, b, ms);
	free(ms->actual_op);
	free(ms->op_list);
	free(ms);
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
	// 	// ft_printf("index: %d\n", a->index);
	// 	ft_printf("%d\n", a->value);
	// 	// ft_printf("value: %d\n", a->next->value);
	// 	// ft_printf("value: %d\n", a->next->next->value);
	// 	// ft_printf("*-----------*\n");
	// 	a = a->next;
	// }
	// while (b->next && !b->is_separator)
	// {
	// 	ft_printf("b  %d\n", b->value);
	// 	b = b->next;
	// }
	free(a);
	free(b);
	// system("leaks a.out");
}
