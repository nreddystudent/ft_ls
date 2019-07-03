/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:38:30 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/03 14:38:32 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>
#include "./list.c"
int		ft_check_args(char **argv, int *ptri, unsigned char *c)
{
	int		x;

	while (argv[*ptri][0] == '-')
	{
		x = 0;
		while (argv[*ptri][x] != '\0')
		{
			if (argv[*ptri][x] == 'a')
				*c=1;
			if (argv[*ptri][x] == 'l')
				*c+=2;
			if (argv[*ptri][x] == 'r')
				*c+=4;
			if (argv[*ptri][x] == 'R')
				*c+=8;
			x++;
		}
			
		*ptri = *ptri + 1;
	}
	return (*ptri);
}
void	ft_MF(int *ptri, char **argv, int argc, struct dirent *ptrf, t_list *mylist)
{
	DIR		*currentfile;
	t_list	*new;

	while (*ptri != argc)
	{
		currentfile = opendir(argv[*ptri]);
		ft_putstr(argv[*ptri]);
		ft_putstr(":\n");
		while((ptrf = readdir(currentfile)) != NULL)
			ft_listcreate(&mylist, &new, ptrf);
		ft_printlist(mylist);
		*ptri = *ptri + 1;
		if(*ptri != argc) 
			ft_putstr("\n\n");
	}
}
void	ft_ls(int argc, char **argv)
{
	int 	i;
	DIR		*currentfile; 
	struct 	dirent f1, *ptrf;
	unsigned char c;
	t_list *mylist;
	
	ptrf = &f1;
	c = 0;
	mylist = NULL;
	i = 1;
	while (i != argc)
	{
		i = ft_check_args(argv, &i, &c);
		if ((argc-1) - i > 0)
		{
			ft_MF(&i, argv, argc, &f1, mylist);
			break;
		}
		currentfile = opendir(argv[i]);
		while((ptrf = readdir(currentfile)) != NULL)
		{
			if(ft_is_dir(ptrf->d_name) && (c & 8))
			{
				ft_putstr("R");
			}
			printf("%s\t", ptrf->d_name);
			
			
		}
		i++;
	}
		ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	ft_ls(argc, argv);
	return (0);
}
