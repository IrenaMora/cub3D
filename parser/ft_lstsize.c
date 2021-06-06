#include "parser.h"

int	ft_lstsize(t_list *lst)
{
	long	lstsize;
	t_list	*lst_current;

	lstsize = 0;
	lst_current = lst;
	while (lst_current != NULL)
	{
		lstsize++;
		lst_current = lst_current->next;
	}
	return (lstsize);
}
