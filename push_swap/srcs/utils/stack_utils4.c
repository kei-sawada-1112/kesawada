/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:08:24 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/05 21:50:24 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delone_stack(t_stack **a)
{
	t_stack	*current;

	if (!a || !*a)
		return ;
	current = *a;
	if ((*a)->next)
	{
		*a = (*a)->next;
		free(current);
	}
	else
	{
		free(current);
		*a = NULL;
	}
}

void	free_all(t_stack *a, t_stack *b, t_ms *ms)
{
	while(!a->next->is_separator)
		delone_stack(&a);
	free(a);
	a = NULL;
	free(b);
	b = NULL;
	clear_operation(&ms->actual_op);
	clear_operation(&ms->op_list);
	free(ms);
}

t_ms	*init_ms(void)
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
