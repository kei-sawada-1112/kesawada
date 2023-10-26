/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:00:05 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/26 17:45:45 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	append_stack(t_stack **stack, int num, int pos)
{
	t_stack	*new_stack;

	new_stack = ft_stacknew(num, pos);
	if (!(*stack)->prev)
		*stack = new_stack;
	else
		ft_addstack_back(stack, &new_stack);
}

static void	init_stack(t_stack **a, int size, char **argv, int no_arg)
{
	long	num;
	int		i;
	int		array[size];

	i = 0 - no_arg;
	while (argv[++i])
	{
		if (!is_numstr(argv[i]))
		{
			ft_printf("Error\n");
			exit (1);
		}
		num = ft_strtol(argv[i], 10);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_printf("Error\n");
			exit (1);
		}
		array[i] = num;
		append_stack(a, num, i - 1 + no_arg);
	}
	set_index_to_value(*a);
}

static void	set_separator(t_stack **a, t_stack **b)
{
	*a = ft_stacknew(0, 0);
	*b = ft_stacknew(0, 0);
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
			len++;
		argc = len;
	}
	init_stack(a, argc, argv, no_arg);
}
