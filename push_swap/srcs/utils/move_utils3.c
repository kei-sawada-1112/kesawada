/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:44:23 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/10 20:53:28 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_ab(t_stack **a, t_stack **b)
{
	return (rotate_a(a, b) | rotate_b(a, b));
}

int	rotate_rev_ab(t_stack **a, t_stack **b)
{
	return (rotate_rev_a(a, b) | rotate_rev_b(a, b));
}
