/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:44:23 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/29 16:58:16 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_ab(t_stack **a, t_stack **b, t_ms *ms)
{
	(void)ms;

	return (rotate_a(a, b, ms) | rotate_b(a, b, ms));
}

int	rotate_rev_ab(t_stack **a, t_stack **b, t_ms *ms)
{
	(void)ms;

	return (rotate_rev_a(a, b, ms) | rotate_rev_b(a, b, ms));
}
