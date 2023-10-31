/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_16.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:11:01 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/31 21:59:54 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_consecutive(t_stack *start, int index, int dir)
{
	int		count;
	t_stack *current;

	count = 0;
	if (dir)
		current = start->next;
	else
		current = start->prev;
	while (!current->next->is_separator)
	{
		if (current->index == index + count + 1)
		{
			count++;
			current = start;
		}
		else if (current->index == index + count)
			break;
		if (dir)
			current = current->next;
		else
			current = current->prev;
	}
	return (count);
}
