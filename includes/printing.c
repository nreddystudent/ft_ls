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
	ft_putnbr(mylist->filesize);
	ft_putstr("   ");
}

void ft_getlinks(t_mything *mylist, char *path) 
{
	struct stat files;
	if (mylist->permission[0] == 'l')
			lstat(path, &files);
	else
		stat(path, &files);
	mylist->nlink = files.st_nlink;
}
int			ft_islink(const char *pname)
{
	struct stat s;

	lstat(pname, &s);
	return (S_ISLNK(s.st_mode));
}

void	ft_getsize(t_mything *mylist, char *path)
{
	struct stat files;

	if (mylist->permission[0] == 'l')
		lstat(path, &files);
	else
		stat(path, &files);
	mylist->filesize = files.st_size;
}
