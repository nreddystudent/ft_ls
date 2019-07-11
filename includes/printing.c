#include "../libft/libft.h"
#include "../ft_ls.h"

void	ft_printlong(t_mything *mylist)
{
	ft_putstr(mylist->permission);
	ft_putstr("   ");
	ft_putnbr(mylist->nlink);
	ft_putstr("   ");
	ft_putstr(mylist->user);
	ft_putstr("   ");
	ft_putstr(mylist->group);
	ft_putstr("   ");
}

void ft_getlinks(t_mything *mylist, char *path) 
{
	char *temp1;
	char *temp2;
	struct stat files;

	temp1 = ft_strjoin(path, "/");
	temp2 = ft_strjoin(temp1, mylist->d_name);
		stat(temp2, &files);
	mylist->nlink = files.st_nlink;
	free(temp1);
	free(temp2);
}
int			ft_islink(const char *pname)
{
	struct stat s;

	lstat(pname, &s);
	return (S_ISLNK(s.st_mode));
}
