/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:27:53 by kei               #+#    #+#             */
/*   Updated: 2023/09/12 17:42:48 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	**alloc_memory(size_t num_elements)
{
	size_t	i;
	void	**array;

	array = malloc(num_elements * sizeof(void *));
	if (!array)
		return (NULL);
	i = 0;
	while (i < num_elements)
	{
		array[i] = NULL;
		i++;
	}
	return (array);
}

void	free_memory(void **any, size_t num_elements)
{
	size_t	i;

	if (!any)
		return ;
	i = 0;
	while (i < num_elements)
	{
		free((any)[i]);
		any[i] = NULL;
		i++;
	}
	free (any);
}
