/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:35:37 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/23 18:26:22 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_info *a, t_info *b, int argc, char **argv)
{
	(void)argv;
	(void)b;
	ft_printf("median: %d\n", get_median(a->stack, argc - 1));
	// ft_stackrot_rev(a, b);
	// ft_stackrot_rev(a, b);
	// swap_top(a, b);
	rotate(a, b);
	// rotate_rev(a, b);
	// push(a, b);
	// swap_top(a, b);
	// swap_top(a, b);
}

void	init_info(t_info *a)
{
	a->push_count = 0;
	a->rotate_count = 0;
	a->stack = NULL;
	a->table = NULL;
}

int main(int argc, char **argv)
{
	t_info	*a;
	t_info	*b;

	a = malloc(sizeof(t_info));
	b = malloc(sizeof(t_info));
	init_info(a);
	init_info(b);
	if (argc == 1)
		return (0);
	init_stack(&(a->stack), argv);
	// init_stack(&(b->stack), NULL);
	push_swap(a, b, argc, argv);
	a->stack = a->stack->next;
	while (a->stack->next && !a->stack->is_separator)
	{
		ft_printf("value: %d\n", a->stack->value);
		ft_printf("next : %d\n", a->stack->next->value);
		ft_printf("prev : %d\n", a->stack->prev->value);
		// ft_printf("value : %d\n", b->stack->next->value);
		a->stack = a->stack->next;
	}
	// ft_printf("%d\n", b->stack->prev->value);
}
