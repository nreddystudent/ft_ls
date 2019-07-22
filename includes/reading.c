#include "../ft_ls.h"
#include "../libft/libft.h"

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

void	ft_readr(char *path, unsigned char c,
		t_mything *mylist, t_tots total)
{
	char	*str1;
	char	*str2;

	(void)total;
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