/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:41:31 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/05 21:13:02 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_operation(t_op_list **list, int op)
{
	t_op_list	*new_node;
	t_op_list	*current;

	new_node = malloc(sizeof(t_op_list));
	new_node->op = op;
	new_node->next = NULL;
	if (!*list)
		*list = new_node;
	else
	{
		current = *list;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

void	delone_operation(t_op_list **list)
{
	t_op_list	*current;
	t_op_list	*prev;

	prev = NULL;
	if (!*list)
		return ;
	current = *list;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	if (prev)
		prev->next = NULL;
	else
		*list = NULL;
	free(current);
}

void	clear_operation(t_op_list **list)
{
	if (!*list)
		return ;
	while (*list)
		delone_operation(list);
}

void	copy_operation(t_ms *ms, t_op_list *list)
{
	int	op;

	while (list)
	{
		op = list->op;
		add_operation(&ms->actual_op, op);
		list = list->next;
	}
	clear_operation(&list);
}
