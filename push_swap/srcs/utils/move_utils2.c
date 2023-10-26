/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:24:52 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/26 21:44:19 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_rev_a(t_stack **a, t_stack **b, t_ms *ms)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*last_second;
	t_stack	*nil;
	(void)ms;

	(void)b;
	if ((*a)->next == (*a)->prev)
		return (0);
	last = ft_stacklast(*a);
	nil = *a;
	first = nil->next;
	last_second = last->prev;
	nil->next = last;
	nil->prev = last_second;
	last->prev = nil;
	last->next = first;
	first->prev = last;
	last_second->next = nil;
	return (1);
}

int	rotate_rev_b(t_stack **a, t_stack **b, t_ms *ms)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*last_second;
	t_stack	*nil;
	(void)ms;

	(void)a;
	if ((*b)->next == (*b)->prev)
		return (0);
	last = ft_stacklast(*b);
	nil = *b;
	first = nil->next;
	last_second = last->prev;
	nil->next = last;
	nil->prev = last_second;
	last->prev = nil;
	last->next = first;
	first->prev = last;
	last_second->next = nil;
	return (1);
}

int	rotate_a(t_stack **a, t_stack **b, t_ms *ms)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second;
	t_stack *nil;
	(void)ms;

	(void)b;
	if ((*a)->next == (*a)->prev)
		return (0);
	last = ft_stacklast(*a);
	nil = *a;
	first = nil->next;
	second = first->next;
	nil->next = second;
	nil->prev = first;
	second->prev = nil;
	last->next = first;
	first->prev = last;
	first->next = nil;
	return (1);
}

int	rotate_b(t_stack **a, t_stack **b, t_ms *ms)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second;
	t_stack *nil;
	(void)ms;

	(void)a;
	if ((*b)->next == (*b)->prev)
		return (0);
	last = ft_stacklast(*b);
	nil = *b;
	first = nil->next;
	second = first->next;
	nil->next = second;
	nil->prev = first;
	second->prev = nil;
	last->next = first;
	first->prev = last;
	first->next = nil;
	return (1);
}

