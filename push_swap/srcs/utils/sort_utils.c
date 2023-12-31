/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:57:01 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/10 20:55:01 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_count(t_stack *a)
{
	int	max;
	int	count;

	max = 0;
	count = 1;
	while (!a->next->is_separator)
	{
		if (a->index + 1 == a->next->index)
		{
			count++;
			if (count > max)
				max = count;
			a = a->next;
			continue ;
		}
		a = a->next;
		count = 1;
	}
	return (max);
}

int	get_current_pos(t_stack *b, int index)
{
	t_stack	*current;
	int		pos;

	current = b->next;
	pos = 1;
	while (1)
	{
		if (current->index == index)
			return (pos);
		current = current->next;
		pos++;
	}
}

void	push_b_and_rotate(t_stack **a, t_stack **b, int *i)
{
	t_stack	*current;
	int		index;
	int		next_count;
	int		sorted;
	int		size;

	sorted = sorted_count(*a);
	size = ft_stacksize(*a) - sorted;
	index = (ft_stacksize(*a) + sorted_count(*a)) / 2;
	current = (*a)->next;
	while (ft_stacksize(*b) != size / 2)
	{
		if (current->index < index)
			execute_and_write(a, b, PB);
		else
		{
			next_count = count_descending(*b, sorted);
			if (next_count && (*b)->next->index != sorted + next_count)
				execute_and_write(a, b, RR);
			else
				execute_and_write(a, b, RA);
		}
		current = (*a)->next;
		(*i)--;
	}
}

void	set_state(t_stack *b, t_ms *ms, int border)
{
	if (ft_stacksize(b) <= border)
		ms->state = SIMPLE_SORT;
	else
		ms->state = B_TO_A;
}

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
