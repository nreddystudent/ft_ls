#include <dirent.h>
#include "test.h"
#include <stdio.h>
#include "./libft/libft.h"

int		ft_check_args(int argc, char **argv)
{
	int		i;

	i = 1;
	while (argv[i][0] == '-')
		i++;
	return(i);
}
void	ft_ls(int argc, char **argv)
{
	int 	i;
	DIR		*currentfile; 
	struct 	dirent *ptrf, f1;

	ptrf = &f1;
	i = ft_check_args(argc, argv);
	currentfile = opendir(argv[i]);
	while((ptrf = readdir(currentfile)) != NULL)
		printf("%s\t", ptrf->d_name);
	printf("\n");
}

int		main(int argc, char **argv)
{
	ft_ls(argc, argv);
	return (0);
}
