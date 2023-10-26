/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:22:23 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/27 04:52:32 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_stacksize(t_stack *a)
{
	int count;

	count = 0;
	a = a->next;
	while (!a->is_separator)
	{
		count++;
		a = a->next;
	}
	return (count);
}

void	add_trans_list(t_trans_list **list, int count)
{
	t_trans_list	*new_node;

	new_node = malloc(sizeof(t_trans_list));
	new_node->count = count;
	new_node->next = NULL;
	if (!*list)
		*list = new_node;
	else
	{
		new_node->next = *list;
		*list = new_node;
	}
}

void	delone_trans_list(t_trans_list **list)
{
	t_trans_list	*current;

	if (!list || !*list)
		return ;
	current = *list;
	if ((*list)->next)
	{
		*list = (*list)->next;
		free(current);
	}
	else
	{
		free(current);
		*list = NULL;
	}
}
