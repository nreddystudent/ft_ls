#include "./libft/libft.h"

t_list	*ft_listcreate(char *s, t_list *Mylist)
{
	if (Mylist == NULL)
	{
		Mylist = ft_lstnew(s, ft_strlen(s));
		ft_putstr(Mylist->content);
	}
	return (Mylist);

}
