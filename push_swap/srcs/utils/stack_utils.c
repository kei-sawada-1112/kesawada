/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:04:49 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/23 17:47:30 by kesawada         ###   ########.fr       */
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
	new->current_stack = 0;
	new->is_separator = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next && !stack->next->is_separator)
		stack = stack->next;
	return (stack);
}

void	ft_addstack_front(t_stack **stack, t_stack **new)
{
	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = *new;
		(*new)->prev = (*new);
		(*new)->next = (*new);
		return ;
	}
	(*stack)->next = (*new);
	(*new)->prev = *stack;
	(*new)->next = (*stack)->next;
	(*stack)->next->prev = (*new);
}

void	ft_addstack_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		new->prev = new;
		new->next = new;
		return ;
	}
	last = ft_stacklast(*stack);
	last->next = new;
	new->next = *stack;
	new->prev = last;
	(*stack)->prev = new;
}

void	ft_stackmove(t_stack *to, t_stack *from)
{
	if (!from || !to)
		return ;
	ft_addstack_front(&to, &from);
	from->next->prev = from->prev;
	from->prev->next = from->next;
	from->prev = to;
	from->next = to->next;
	// to = to->next;
}
