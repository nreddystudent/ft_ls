#include "./libft/libft.h"

void	ft_listcreate(char *s, t_list *Mylist)
{
		Mylist = ft_lstnew(s, ft_strlen(s));
		ft_putstr(Mylist->content);
		return ;

}
