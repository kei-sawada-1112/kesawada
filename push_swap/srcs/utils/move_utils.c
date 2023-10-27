/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:48:09 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/27 12:05:08 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	swap_a(t_stack **a, t_stack **b, t_ms *ms)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	(void)ms;

	(void)b;
	if((*a)->next == (*a)->prev)
		return (0);
	first = (*a)->next;
	second = first->next;
	third = second->next;
	first->prev->next = second;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	if (!third->is_separator)
	{
		first->next = third;
		third->prev = first;
	}
	else
	{
		first->next = second->prev;
		second->prev->prev = first;
	}
	return (1);
}

int	swap_b(t_stack **a, t_stack **b, t_ms *ms)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	(void)ms;

	(void)a;
	if((*b)->next == (*b)->prev)
		return (0);
	first = (*b)->next;
	second = first->next;
	third = second->next;
	first->prev->next = second;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	if (!third->is_separator)
	{
		first->next = third;
		third->prev = first;
	}
	else
	{
		first->next = second->prev;
		second->prev->prev = first;
	}
	return (1);
}

int swap_ab(t_stack **a, t_stack **b, t_ms *ms)
{
	int	count;
	(void)ms;

	count = 0;
	count = swap_a(a, b, ms);
	count = swap_b(a, b, ms);
	return (count);
}

int push_b(t_stack **a, t_stack **b, t_ms *ms)
{
	t_stack	*a_nil;
	t_stack *a_first;

	(void)ms;
	if ((*a)->next->is_separator)
		return (0);
	a_nil = *a;
	a_first = a_nil->next;
	a_first->next->prev = a_nil;
	a_nil->next = a_first->next;
	ft_addstack_front(b, &a_first);
	return (1);
}

int push_a(t_stack **a, t_stack **b, t_ms *ms)
{
	t_stack	*b_nil;
	t_stack *b_first;
	(void)ms;

	if ((*b)->next->is_separator)
		return (0);
	b_nil = *b;
	b_first = b_nil->next;
	b_first->next->prev = b_nil;
	b_nil->next = b_first->next;
	ft_addstack_front(a, &b_first);
	return (1);
}
