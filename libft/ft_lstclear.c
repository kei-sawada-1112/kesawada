/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:59:37 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/27 10:59:40 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_lst;

	if (!lst)
		return ;
	while (*lst)
	{
		current_lst = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(current_lst, del);
	}
}
