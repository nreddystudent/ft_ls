
#include "../libft/libft.h"
#include "../ft_ls.h"

int		ft_checkextra(char *filename, int c)
{
	if (!(c & FLAG_A) && (filename[0] == '.') && (!(c & FLAG_AL)))
			return (1);
		if (c & FLAG_AL && !(c & FLAG_A))
		{
			if ((ft_strcmp(".", filename) == 0)
			|| (ft_strcmp ("..", filename) == 0))
				return (1);
		}
	return(0);
}

void	ft_putextra(t_mything *mylist, int c)
{
	if (mylist->permission[0] == 'd' && c & FLAG_G)
		ft_putstr("\033[0;34m");
	else if (mylist->permission[0] == 'l' && c & FLAG_G)
		ft_putstr("\033[0;35m");
	else if (mylist->permission[3] == 'x' && c & FLAG_G)
		ft_putstr("\033[0;31m");
	ft_putstr(mylist->d_name);
	ft_putstr("\033[0m");
	if (mylist->permission[0] == 'd' && c & FLAG_P)
		ft_putchar('/');
}