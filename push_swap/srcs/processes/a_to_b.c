/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:49:07 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/26 17:04:50 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_a_to_b(t_stack **a, t_stack **b, t_ms *ms)
{
	t_stack	*current;
	int		i;

	i = ms->size / 2;
	current = (*a)->next;
	while (i > 0)
	{
		if (current->index < ms->size / 2)
		{
			if (current->pos > ms->size / 2)
			{
				while (!current->prev->is_separator)
					ms->count += rotate_rev_a(a, NULL, ms);
			}
			else
			{
				while (!current->prev->is_separator)
					ms->count += rotate_a(a, NULL, ms);
			}
			current = current->next;
			ms->size -= push_b(a, b, ms);
			ms->count += 1;
			(*b)->next->pos = --i;
		}
		else
			current = current->next;
	}
	ms->state = B_TO_A;
	ft_printf("------a size: %d------\n", ms->size);
}

void	send_b_to_a(t_stack **a, t_stack **b, t_ms *ms)
{
	t_stack	*current;
	int		i;
	int		half_size;

	ft_printf("------before b size: %d------\n", ft_stacksize(*b));
	half_size = ft_stacksize(*b) / 2;
	i = ft_stacksize(*b) / 2;
	current = (*a)->next;
	while (i > 0)
	{
		if (current->index < half_size)
		{
			if (current->pos > half_size)
			{
				while (!current->prev->is_separator)
					ms->count += rotate_rev_b(NULL, b, ms);
			}
			else
			{
				while (!current->prev->is_separator)
					ms->count += rotate_b(NULL, b, ms);
			}
			current = current->next;
			ms->size += push_a(a, b, ms);
			ms->count += 1;
			(*a)->next->pos = --i;
		}
		else
			current = current->next;
	}
	ft_printf("------after b size: %d------\n", ft_stacksize(*b));
	if (ft_stacksize(*b) <= 5)
		ms->state = END;
}
