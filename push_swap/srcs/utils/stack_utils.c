/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:04:49 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/03 13:27:18 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->is_separator = 0;
	new->index = 0;
	new->next = new;
	new->prev = new;
	return (new);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (!stack->next->is_separator)
		stack = stack->next;
	return (stack);
}

void	ft_addstack_front(t_stack **stack, t_stack **new)
{
	t_stack	*first;
	t_stack	*nil;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = *new;
		(*new)->prev = (*new);
		(*new)->next = (*new);
		return ;
	}
	nil = *stack;
	first = (*stack)->next;
	nil->next = *new;
	(*new)->prev = nil;
	(*new)->next = first;
	first->prev = *new;
}

void	ft_addstack_back(t_stack **stack, t_stack **new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = *new;
		(*new)->prev = *new;
		(*new)->next = *new;
		return ;
	}
	last = ft_stacklast(*stack);
	last->next = *new;
	(*new)->next = *stack;
	(*new)->prev = last;
	(*stack)->prev = *new;
}
