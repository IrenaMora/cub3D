#include "parser.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_last;

	if (lst[0] == NULL)
	{
		lst[0] = new;
		return ;
	}
	lst_last = ft_lstlast(lst[0]);
	lst_last->next = new;
}
