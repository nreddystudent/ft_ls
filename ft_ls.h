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

void	ft_recursion(char *argv, struct dirent *ptrf);
int		ft_is_dir(const char *pname);
void	ft_listcreate(t_list **mylist, t_list **new, struct dirent *ptrf);
void	ft_printlist(t_list *mylist);
