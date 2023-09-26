/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:32:33 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/26 12:53:35 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_lst;

	while (*lst)
	{
		current_lst = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(current_lst, del);
	}
}
