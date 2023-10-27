/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:44:23 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/27 12:05:54 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_ab(t_stack **a, t_stack **b, t_ms *ms)
{
	int	count;
	(void)ms;

	count = 0;
	count = rotate_a(a, b, ms);
	count = rotate_b(a, b, ms);
	return (count);
}

int	rotate_rev_ab(t_stack **a, t_stack **b, t_ms *ms)
{
	int	count;
	(void)ms;

	count = 0;
	count = rotate_rev_a(a, b, ms);
	count = rotate_rev_b(a, b, ms);
	return (count);
}
