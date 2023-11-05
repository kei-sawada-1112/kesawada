/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:35:37 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/05 11:06:10 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_process(t_stack **a, t_stack **b, t_ms *ms)
{
	static	t_push_swap_process f[] =
	{
		send_a_to_b, send_b_to_a, quick_sort_b, \
		send_under_half, simple_sort, back_to_b,
	};

	f[ms->state](a, b, ms);
}

static void	free_all(t_stack *a, t_ms *ms)
{
	a = a->prev->prev;
	while(a)
	{
		free(a->next);
		a = a->prev;
	}
	clear_operation(&ms->actual_op);
	clear_operation(&ms->op_list);
	free(ms);
}

static t_ms	*init_ms()
{
	t_ms	*ms;

	ms = malloc(sizeof(t_ms));
	if (!ms)
		return (NULL);
	ms->op = INIT;
	ms->count = 0;
	ms->min_turn = 15;
	ms->limit_count = 15;
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
	set_index_to_value(*a);
	if (in_order(*a))
		return ;
	ms = init_ms();
	if (!ms)
		error_and_exit();
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
		t_op_list *current;
		current = ms->actual_op;
		while (current)
		{
			print_op(current->op);
			current = current->next;
		}
	}
	else
		ms->state = A_TO_B;
	while (ms->state != END)
		handle_process(a, b, ms);
	free_all(*a, ms);
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
	free(a);
	free(b);
	// system("leaks push_swap");
}
