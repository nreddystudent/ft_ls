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

void	ft_listcreate(mything **mylist, mything **new, struct dirent *ptrf)
{
	if (*mylist == NULL)
		*mylist = ft_listnew(ptrf->d_name, ft_strlen(ptrf->d_name));
	else
	{
		*new = ft_listnew(ptrf->d_name, ft_strlen(ptrf->d_name));
		(*new)->next = *mylist;
		mylist = new;
	}
}

void	ft_printlist(mything *mylist)
{
	while (mylist != NULL)
	{
		ft_putstr(mylist->d_name);
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

void	ft_read(char *path, unsigned char c)
{
	DIR				*file;
	struct dirent	*ptr;
	mything			*ptrmystuff;
	mything			*new;

	(void)c;
	new = NULL;
	file = opendir(path);
	while ((ptr = readdir(file)))
		ft_listcreate(&ptrmystuff, &new, ptr);
	ft_printlist(ptrmystuff);
}

void	ft_ls(int argc, char **argv, unsigned char c, int i)
{
	(void)c;
	(void)argc;
	ft_read(argv[i], c);
}
