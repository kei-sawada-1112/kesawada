/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_to_bottom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:59:59 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/27 00:31:53 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted_to_bottom(t_stack **a, t_stack **b, t_ms *ms)
{
	int	i;

	i = 0;
	while (!(*b)->next->is_separator)
	{
		ms->count += push_a(a, b, ms);
		print_op(PA);
		i++;
	}
	while (--i >= 0)
	{
		ms->count += rotate_a(a, NULL, ms);
		print_op(RA);
	}
	if (in_order(*a))
	{
		ms->state = END;
		return ;
	}
	if (ms->trans_list && !in_order(*a))
	{
		while (ms->trans_list->count--)
		{
			ms->count += push_b(a, b, ms);
			print_op(PB);
		}
		delone_trans_list(&ms->trans_list);
	}
	 else
		ms->state = A_TO_B_NEXT;
}
