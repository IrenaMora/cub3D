#include "parser.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lst_current;

	if (lst == NULL)
		return (NULL);
	lst_current = lst;
	while (lst_current->next != NULL)
		lst_current = lst_current->next;
	return (lst_current);
}
