/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:35:37 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/23 10:49:29 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, int argc, char **argv)
{
	(void)argv;
	ft_printf("median: %d\n", get_median(*a, argc - 1));
}

int main(int argc, char **argv)
{
	t_stack	*a;
	// t_stack	*b;

	if (argc == 1)
		return (0);
	init_stack(&a, argv);
	push_swap(&a, argc, argv);
	ft_printf("%d\n", a->prev->value);
}