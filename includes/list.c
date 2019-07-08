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

mything	*ft_listcreate(mything *mylist, mything *new, struct dirent *ptrf)
{
	if (mylist == NULL)
	{
		mylist = ft_listnew(ptrf->d_name);
		return (mylist);
	}
	else
	{
		new = ft_listnew(ptrf->d_name);
		ft_listadd(&mylist, new);
		return (mylist);
	}
}

void	ft_printlist(mything *mylist)
{
	while (mylist != NULL)
	{
		ft_putstr(mylist->d_name);
		ft_putstr("   ");
		mylist = mylist->next;
	}
	ft_putchar('\n');
}

int		ft_is_dir(const char *pname)
{
	struct stat s;

	stat(pname, &s);
	return (S_ISDIR(s.st_mode));
}

void	ft_read(char *path, unsigned char c)
{
	DIR				*file;
	struct dirent	*ptr;
	mything			*ptrmystuff;
	mything			*new;

	ptrmystuff = NULL;
	new = NULL;
	file = opendir(path);
	while ((ptr = readdir(file)))
	{
		if (!(c & 1) && (ptr->d_name[0] == '.'))
			continue ;
		ptrmystuff = ft_listcreate(ptrmystuff, new, ptr);
	}
	closedir(file);
	if (c & 8)
		ft_readr(path, c);
	ft_sortlist(&ptrmystuff, c);
	ft_printlist(ptrmystuff);
}

void	ft_ls(int argc, char **argv, unsigned char c, int i)
{
	(void)c;
	(void)argc;
	ft_read(argv[i], c);
}
