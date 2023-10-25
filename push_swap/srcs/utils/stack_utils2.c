/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:00:05 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/25 10:13:15 by kesawada         ###   ########.fr       */
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

void	init_stack(t_stack **a, int argc, char **argv)
{
	int		i;
	long	num;
	int		array[argc];

	i = 0;
	while (argv[++i])
	{
		if (!is_numstr(argv[i]))
		{
			ft_printf("Error\n");
			exit(1);
		}
		num = ft_strtol(argv[i], 10);
		ft_printf("num: %d\n", num);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_printf("Error\n");
			exit(1);
		}
		array[i] = num;
		append_stack(a, num, i - 1);
	}
	set_index_to_value(*a, array, argc);
}

void	init(t_stack **a, t_stack **b, int argc, char **argv)
{
	*a = ft_stacknew(0, 0);
	*b = ft_stacknew(0, 0);
	(*a)->is_separator = 1;
	(*b)->is_separator = 1;
	init_stack(a, argc, argv);
}
