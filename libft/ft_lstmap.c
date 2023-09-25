/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:33:18 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/25 18:33:20 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*current_node;

	if (!lst || !f)
		return (NULL);
	map = ft_lstnew(f(lst->content));
	if (!map)
		return (NULL);
	current_node = map;
	lst = lst->next;
	while (lst)
	{
		current_node->next = ft_lstnew(f(lst->content));
		if (!current_node->next)
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		current_node = current_node->next;
		lst = lst->next;
	}
	return (map);
}
