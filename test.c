#include <dirent.h>
#include "test.h"
#include <stdio.h>
#include "./libft/libft.h"
#include "./list.c"
int		ft_check_args(int argc, char **argv, unsigned char *c, int *ptri)
{
	int		x;

	while (argv[*ptri][0] == '-')
	{
		x = 0;
		while (argv[*ptri][x] != '\0')
		{
			if (argv[*ptri][x] == 'a')
				ft_putstr("all");
			if (argv[*ptri][x] == 'l')
				ft_putstr("long");
			if (argv[*ptri][x] == 'r')
				ft_putstr("reverse");
			if (argv[*ptri][x] == 'R')
				ft_putstr("recursion");
			x++;
		}
			
		*ptri = *ptri + 1;
	}
	return (*ptri);
}
void	ft_MF(int *ptri,char **argv, int argc, struct dirent *ptrf)
{
	DIR		*currentfile;
	t_list *Mylist;

	while (*ptri != argc)
	{
		currentfile = opendir(argv[*ptri]);
		ft_putstr(argv[*ptri]);
		ft_putstr(":\n");
		while((ptrf = readdir(currentfile)) != NULL)
		{
			ft_listcreate(ptrf->d_name, Mylist);
			ft_putchar('\t');
		}
		*ptri = *ptri + 1;
		(*ptri != argc) ? ft_putstr("\n\n") : ft_putchar('\n');
	}
}
void	ft_ls(int argc, char **argv)
{
	int 	i;
	DIR		*currentfile; 
	struct 	dirent *ptrf, f1;
	unsigned char c;

	i = 1;
	ptrf = &f1;
	while (i != argc)
	{
		i = ft_check_args(argc, argv, &c, &i);
		if ((argc-1) - i > 0)
		{
			ft_MF(&i, argv, argc, ptrf);
			break;
		}
		currentfile = opendir(argv[i]);
		while((ptrf = readdir(currentfile)) != NULL)
		{
			ft_putstr(ptrf->d_name);
			ft_putchar('\t');
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	ft_ls(argc, argv);
	return (0);
}
