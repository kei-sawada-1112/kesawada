/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:18:28 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/06 13:59:41 by kesawada         ###   ########.fr       */
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

int	execute_and_write(t_stack **a, t_stack **b, t_ms *ms, int op)
{
	static t_operation	f[] = \
	{
		swap_a, push_b, rotate_a, rotate_rev_a, \
		swap_b, push_a, swap_ab, rotate_b, \
		rotate_ab, rotate_rev_b, rotate_rev_ab
	};

	print_op(op);
	return (f[op](a, b, ms));
}

void	error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
