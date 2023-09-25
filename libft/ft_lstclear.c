/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:32:33 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/25 18:32:34 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_lst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		current_lst = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(current_lst, del);
	}
}
