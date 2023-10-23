/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:00:05 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/23 11:58:16 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_stack(t_stack **stack, int num)
{
	t_stack	*new_stack;

	new_stack = ft_stacknew(num);
	if (!(*stack))
		*stack = new_stack;
	else
		ft_addstack_back(stack, new_stack);
}

void	init_stack(t_stack **stack, char **argv)
{
	int			i;
	long		num;
	t_hashtable	*table;

	table = init_hashtable();
	append_stack(stack, 0);
	(*stack)->is_separator = 1;
	if (!argv)
	{
		return ;
	}
	i = 0;
	while (argv[++i])
	{
		if (!is_numstr(argv[i]))
		{
			ft_printf("Error\n");
			exit(1);
		}
		num = ft_strtol(argv[i], 10);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_printf("Error\n");
			exit(1);
		}
		add_to_hashtable(table, num, i);
		append_stack(stack, num);
	}
	*stack = (*stack)->next;
}
