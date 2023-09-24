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
