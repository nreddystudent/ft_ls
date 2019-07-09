#include <dirent.h>
#include "./libft/libft.h"
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <sys/xattr.h>
#include <string.h>

typedef	struct		mystuff
{
	char			*d_name;
	struct mystuff	*next;
}					mything;
void	ft_recursion(char *argv, struct dirent *ptrf);
mything	*ft_listnew(char *content);
int		ft_is_dir(const char *pname);
mything	*ft_listcreate(mything *mylist, mything *new, struct dirent *ptrf);
void	ft_printlist(mything *mylist);
void	ft_ls(int argc, char **argv, unsigned char c, int i);
void	ft_read(char *path, unsigned char c);
void	ft_listadd(mything **list, mything *new);
void	ft_sortlist(mything **headref, unsigned char c);
void	frontbacksplit(mything *head, mything **fh, mything **bh);
mything	*ft_sortedmerge(mything *fh, mything *bh, unsigned char c);
void	ft_readr(char *path, unsigned char c, mything *mylist);