/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:48:09 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/21 19:04:53 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int swap_a(int *a)
{
    int tmp;

    tmp = a[0];
    a[0] = a[1];
    a[1] = tmp;
    return (1);
}

int swap_b(int *b)
{
    int tmp;

    tmp = b[0];
    b[0] = b[1];
    b[1] = tmp;
    return (1);
}

int swap_ab(int *a, int *b)
{
    swap_a(a);
    swap_b(b);
    return (2);
}

int push_a(int *a, int *b)
{
    if (!b)
        return (0);
    a[0] =
}