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

t_mything	*ft_listcreate(t_mything *mylist,
			t_mything *new, struct dirent *ptrf, char *path)
{
	if (mylist == NULL)
	{
		mylist = ft_listnew(ptrf->d_name, path);
		return (mylist);
	}
	else
	{
		new = ft_listnew(ptrf->d_name, path);
		ft_listadd(&mylist, new);
		return (mylist);
	}
}

void		ft_printlist(t_mything *mylist, unsigned char c)
{
	while (mylist != NULL)
	{
		if (c & FLAG_L)
			ft_printlong(mylist);
		ft_putstr(mylist->d_name);
		ft_putstr("   \n");
		mylist = mylist->next;
	}
	ft_putchar('\n');
}

int			ft_is_dir(const char *pname)
{
	struct stat s;

	stat(pname, &s);
	return (S_ISDIR(s.st_mode));
}

void		ft_read(char *path, unsigned char c)
{
	DIR				*file;
	struct dirent	*ptr;
	t_mything		*ptrmystuff;
	t_mything		*new;

	ptrmystuff = NULL;
	new = NULL;
	file = opendir(path);
	if (file == NULL)
		return ;
	while ((ptr = readdir(file)))
	{
		if (!(c & FLAG_A) && (ptr->d_name[0] == '.'))
			continue ;
		ptrmystuff = ft_listcreate(ptrmystuff, new, ptr, path);
	}
	closedir(file);
	ft_sortlist(&ptrmystuff, c);
	if (c & FLAG_R)
		ft_readr(path, c, ptrmystuff);
	ft_printlist(ptrmystuff, c);
	ft_listdel(ptrmystuff);
}

void		ft_ls(int argc, char **argv, unsigned char c, int i)
{
	(void)argc;
	ft_read(argv[i], c);
}
