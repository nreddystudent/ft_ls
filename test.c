#include <dirent.h>
#include "test.h"
#include <stdio.h>
#include "./libft/libft.h"

char *ft_check_args(int argc, char **argv)
{
	int		i;

	i = 0;
	while (argv[i] == ' ' || argv[i] == '-')
		i++;
	while (argv[i] == ' ' || ft_isalpha(argv[i]) == 0)

	return(
}
void	ft_ls(int argc, char **argv)
{
   DIR *currentfile = opendir(argv[1]);
   struct dirent *ptrf, f1;
   ptrf = &f1;

	while((ptrf = readdir(currentfile)) != NULL)
		printf("%s\t", ptrf->d_name);
	printf("\n");
  	
}

int		main(int argc, char **argv)
{
	ft_ls(argc, argv);
	return (0);
}
