/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:00:05 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/10 20:11:52 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_stack(t_stack **stack, int num)
{
	t_stack	*new_stack;

	new_stack = ft_stacknew(num);
	if (!(*stack)->prev)
		*stack = new_stack;
	else
		ft_addstack_back(stack, &new_stack);
}

static void	free_array_noargs(char **argv, int i)
{
	if (is_numstr(argv[0]))
	{
		while (i--)
			free(argv[i]);
		free(argv);
	}
}

static void	init_stack(t_stack **a, int size, char **argv, int no_arg)
{
	long	num;
	int		i;
	int		*array;

	i = 0 - no_arg;
	array = malloc(sizeof(int) * size);
	if (!array)
		error_and_exit();
	while (argv[++i])
	{
		if (!is_numstr(argv[i]))
			error_and_exit();
		num = ft_strtol(argv[i], 10);
		if (num > INT_MAX || num < INT_MIN)
			error_and_exit();
		array[i] = num;
		append_stack(a, num);
	}
	if (!is_valid_value(*a))
		error_and_exit();
	free_array_noargs(argv, i);
	free(array);
}

static void	set_separator(t_stack **a, t_stack **b)
{
	*a = ft_stacknew(0);
	*b = ft_stacknew(0);
	(*a)->index = INT_MIN;
	(*a)->is_separator = 1;
	(*b)->index = INT_MIN;
	(*b)->is_separator = 1;
}

void	init(t_stack **a, t_stack **b, int argc, char **argv)
{
	size_t	len;
	int		no_arg;

	len = 0;
	no_arg = 0;
	set_separator(a, b);
	if (argc == 2)
	{
		no_arg = 1;
		argv = ft_split(argv[1], ' ');
		while (argv[len])
		{
			if (!is_numstr(argv[len]))
				error_and_exit();
			len++;
		}
		argc = len;
	}
	init_stack(a, argc, argv, no_arg);
}
