/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:22:23 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/25 21:20:33 by kesawada         ###   ########.fr       */
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