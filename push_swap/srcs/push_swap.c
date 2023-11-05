/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:35:37 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/05 22:03:16 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_process(t_stack **a, t_stack **b, t_ms *ms)
{
	static t_push_swap_process	f[] = \
	{
		send_a_to_b, send_b_to_a, \
		send_under_half, simple_sort, back_to_b,
	};

	f[ms->state](a, b, ms);
}

static t_ms	*init_ms_and_stack(t_stack **a, t_stack **b, int *size, char **argv)
{
	t_ms	*ms;
	size_t	len;
	t_stack	*tmp;

	len = 0;
	init(a, b, *size, argv);
	set_index_to_value(*a);
	if (in_order(*a))
		exit(0);
	ms = init_ms();
	if (!ms)
		error_and_exit();
	tmp = *a;
	if (*size == 2)
	{
		while (!tmp->next->is_separator)
		{
			tmp = tmp->next;
			len++;
		}
		*size = len + 1;
	}
	return (ms);
}

static void	push_swap(t_stack **a, t_stack **b, int size, char **argv)
{
	t_ms		*ms;
	t_op_list	*current;

	ms = init_ms_and_stack(a, b, &size, argv);
	if (size <= 6)
	{
		sort_under_six(a, b, ms, 0);
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
	free_all(*a, *b, ms);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	push_swap(&a, &b, argc, argv);
}
