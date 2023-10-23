/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 03:24:01 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/23 11:50:37 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_median_five(int sub_array[5], int size)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		if (size == 3)
			count = 1;
		else
			count = 0;
		while (j < size)
		{
			if (sub_array[i] < sub_array[j])
				count++;
			j++;
		}
		if (count == 2)
			return (sub_array[i]);
		i++;
	}
	return (sub_array[0]);
}

static int	calc_median(int *array, int size)
{
	int	*medians;
	int	median;
	int	i;

	medians = malloc(sizeof(int) * (size / 5 + 1));
	if (size <= 5)
		return (calc_median_five(array, size));
	i = 0;
	while (i < size)
	{
		if (i + 5 <= size)
			medians[i / 5] = calc_median_five(&array[i], 5);
		else
			medians[i / 5] = calc_median_five(&array[i], size - i);
		i += 5;
	}
	median = calc_median(medians, size / 5);
	free(medians);
	return (median);
}

int get_median(t_stack *stack, int size)
{
	int	i;
	int *array;
	int	median;

	array = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
	median = calc_median(array, size);
	free(array);
	return median;
}
