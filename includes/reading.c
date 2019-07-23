/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:25:03 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/22 10:25:04 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"
#include "../libft/libft.h"

void		ft_read(char *path, int c)
{
	DIR				*file;
	struct dirent	*ptr;
	t_mything		*ptrarray[2];
	t_tots			total;

	ft_setarray(ptrarray, &total);
	file = opendir(path);
	total.flags = c;
	if (file == NULL)
	{
		checkerrors(path, c);
		return ;
	}
	while ((ptr = readdir(file)))
	{
		if (ft_checkextra(ptr->d_name, c) == 1)
			continue ;
		ptrarray[0] = ft_listcreate(ptrarray, ptr, path, &total);
	}
	closedir(file);
	if (!(c & FLAG_F))
		ft_sortlist(&(ptrarray[0]), c);
	ft_printlist(ptrarray[0], c, total, path);
	checkrecursion(path, c, ptrarray);
	ft_listdel(ptrarray[0]);
}

void		ft_readr(char *path, int c,
		t_mything *mylist)
{
	char	*str1;
	char	*str2;

	while (mylist != NULL)
	{
		str1 = ft_strjoin("/", mylist->d_name);
		str2 = ft_strjoin(path, str1);
		if ((ft_strcmp(".", mylist->d_name) == 0)
		|| (ft_strcmp("..", mylist->d_name) == 0) || (ft_islink(str2)))
		{
			mylist = mylist->next;
			free(str1);
			free(str2);
			continue ;
		}
		free(str1);
		if ((ft_is_dir(str2) == 1))
		{
			ft_putdir(str2);
			ft_read(str2, c);
		}
		free(str2);
		mylist = mylist->next;
	}
}

void		read_mf(char **argv, int c, int i)
{
	i = 0;
	checkfiles(argv, c);
	ft_putendl("\n");
	while (argv[i] != NULL)
	{
		if (opendir(argv[i]))
		{
			ft_putstr(argv[i]);
			ft_putendl(" :");
		}
		if (errno == 20)
		{
			errno = 0;
			i++;
			continue ;
		}
		ft_read(argv[i++], c);
		ft_putchar('\n');
	}
}
