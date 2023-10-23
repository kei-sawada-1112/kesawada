/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:48:09 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/23 10:56:14 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_numstr(char *str)
{
	if (!str || *str == '\0')
		return (0);
	while (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

int	swap_top(t_info *a, t_info *b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	(void)b;
	if(!(a->stack) || !(a->stack->next))
		return (0);
	first = a->stack;
	second = first->next;
	third = second->next;
	a->stack = second;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	return (1);
}

int swap_ab(t_info *a, t_info *b)
{
	int	count;

	count = 0;
	count += swap_top(a, NULL);
	count += swap_top(b, NULL);
	return (count);
}

int push(t_info *a, t_info *b)
{
	if (!a->stack)
		return (0);

	a->push_count += 1;
	b->push_count -= 1;
	ft_stackmove(a->stack, b->stack);
	return (1);
}
