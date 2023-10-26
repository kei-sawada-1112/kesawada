/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:44:30 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/26 15:50:52 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *a, t_stack *b, t_ms *ms)
{
	t_stack	*a_last;
	t_stack	*b_last;

	free(ms->actual_op);
	free(ms->op_list);
	free(ms);
	while (a)
	{
		a_last = ft_stacklast(a);
		free(a_last);
		a_last = NULL;
	}
	while (b)
	{
		b_last = ft_stacklast(b);
		free(b_last);
		b_last = NULL;
	}
}
