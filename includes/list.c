/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:38:20 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/04 16:28:18 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_ls.h"

void	ft_listcreate(t_list **mylist, t_list **new, struct dirent *ptrf)
{
	if (*mylist == NULL)
		*mylist = ft_lstnew(ptrf->d_name, ft_strlen(ptrf->d_name));
	else
	{
		*new = ft_lstnew(ptrf->d_name, ft_strlen(ptrf->d_name));
		ft_lstadd(mylist, *new);
	}
}

void	ft_printlist(t_list *mylist)
{
	while (mylist != NULL)
	{
		ft_putstr(mylist->content);
		ft_putchar('\t');
		mylist = mylist->next;
	}
}

int		ft_is_dir(const char *pname)
{
	struct stat s;

	stat(pname, &s);
	return (S_ISDIR(s.st_mode));
}

void	ft_ls(int argc, char **argv, unsigned char c, int i)
{
	DIR				*file;
	struct dirent	*ptrs;

	ptrs = NULL;
	(void)c;
	(void)argc;
	file = opendir(argv[i]);
	while ((ptrs = readdir(file)))
	{
		ft_putstr(ptrs->d_name);
		ft_putstr("   ");
	}
}
