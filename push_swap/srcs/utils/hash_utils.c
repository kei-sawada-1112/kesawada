/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:40:57 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/23 04:13:09 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_new_node(int value, int i)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->value = value;
	new_node->index = i;
	new_node->next = NULL;
	return (new_node);
}

static void	add_to_list(t_node **list, int value, int i)
{
	t_node	*current;

	current = *list;
	while (current)
	{
		if (current->value == value)
		{
			ft_printf("Error\n");
			exit(1);
		}
		if (!current->next)
		{
			current->next = create_new_node(value, i);
			return;
		}
		current = current->next;
	}
}

void	add_to_hashtable(t_hashtable *table, int value, int i)
{
	int	rem;

	rem = value % TABLE_SIZE;
	if (rem < 0)
		rem = -rem;
	if (!table->entries[rem])
		table->entries[rem] = create_new_node(value, i);
	else
		add_to_list(&table->entries[rem], value, i);
}

t_hashtable	*init_hashtable(void)
{
	t_hashtable	*table;
	int			i;

	table = malloc(sizeof(t_hashtable));
	i = 0;
	while (i < TABLE_SIZE)
	{
		table->entries[i] = NULL;
		i++;
	}
	return (table);
}
