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

t_mything	*ft_listcreate(t_mything **myarray, struct dirent *ptrf, char *path,
			t_tots *total)
{
	if (myarray[0] == NULL)
	{
		myarray[0] = ft_listnew(ptrf->d_name, path, total);
		return (myarray[0]);
	}
	else
	{
		myarray[1] = ft_listnew(ptrf->d_name, path, total);
		ft_listadd(&myarray[0], myarray[1]);
		return (myarray[0]);
	}
}

void		ft_printlist(t_mything *mylist, unsigned char c,
						t_tots total, char *path)
{
	t_mything	*temp;

	temp = mylist;
	if (c & FLAG_L)
	{
		ft_putstr("total ");
		ft_putnbr(total.total);
		ft_putchar('\n');
	}
	while (mylist != NULL)
	{
		if (c & FLAG_L)
			ft_printlong(mylist);
		ft_putstr(mylist->d_name);
		if (mylist->permission[0] == 'l' && c & FLAG_L)
			ft_printlink(path, mylist);
		if (c & FLAG_L)
			ft_putstr("   \n");
		else if (c & FLAG_R)
			ft_checkspacing_R(ft_strlen(mylist->d_name));
		else
			ft_putstr("   ");
		mylist = mylist->next;
	}
	ft_putchar('\n');
	if (c & FLAG_R)
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
	t_mything		*ptrarray[2];
	t_tots			total;

	ft_setarray(ptrarray, &total);
	file = opendir(path);
	if (file == NULL)
	{
		ft_putstr(strerror(errno));
		ft_putchar('\n');
		return ;
	}
	while ((ptr = readdir(file)))
	{
		if (!(c & FLAG_A) && (ptr->d_name[0] == '.'))
			continue ;
		ptrarray[0] = ft_listcreate(ptrarray, ptr, path, &total);
	}
	closedir(file);
	ft_sortlist(&(ptrarray[0]), c);
	ft_printlist(ptrarray[0], c, total, path);
	if (c & FLAG_R)
		ft_readr(path, c, ptrarray[0], total);
	ft_listdel(ptrarray[0]);
}

void		ft_ls(int argc, char **argv, unsigned char c, int i)
{
	(void)argc;
	if (c & FLAG_MF)
	{
		i = 0;
		while (argv[i] != NULL)
		{
			ft_putstr(argv[i]);
			ft_putendl(" :");
			ft_read(argv[i], c);
			i += 1;
		}
	}
	else
		ft_read(argv[i], c);
}
