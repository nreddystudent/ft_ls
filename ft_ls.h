/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:29:26 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/09 11:29:27 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include "./libft/libft.h"
# include <sys/stat.h>
# include <stdio.h>
# include <time.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <string.h>
# include <errno.h>
# define FLAG_A 1
# define FLAG_L 2
# define FLAG_REV 4
# define FLAG_R 8
# define FLAG_T 32
# define FLAG_MF 64
# define MAXPATHLEN 1024

typedef	struct			s_mystuff
{
	char				*d_name;
	char				*user;
	char				*group;
	char				permission[11];
	int					nlink;
	int					filesize;
	char				date[13];
	time_t				rawtime;
	struct s_mystuff	*next;
}						t_mything;

typedef struct			s_tots
{
	int					total;
}						t_tots;

void					ft_recursion(char *argv, struct dirent *ptrf);
t_mything				*ft_listnew(char *content, char *path, t_tots *total);
int						ft_is_dir(const char *pname);
t_mything				*ft_listcreate(t_mything **myarray, struct dirent *ptrf,
						char *path, t_tots *total);
void					ft_printlist(t_mything *mylist, unsigned char c,
						t_tots total, char *path);
void					ft_ls(int argc, char **argv, unsigned char c, int i);
void					ft_read(char *path, unsigned char c);
void					ft_listadd(t_mything **list, t_mything *new);
void					ft_sortlist(t_mything **headref, unsigned char c);
void					frontbacksplit(t_mything *head,
						t_mything **fh, t_mything **bh);
t_mything				*ft_sortedmerge(t_mything *fh,
						t_mything *bh, unsigned char c);
void					ft_readr(char *path,
						unsigned char c, t_mything *mylist);
void					ft_listdel(t_mything *mylist);
void					ft_add_elements(t_mything *mylist, char *path,
						t_tots *total);
void					ft_get_names(t_mything *mylist, struct stat statistics);
void					ft_get_fileperm(t_mything *mylist,
						struct stat statistics, char *path);
void					ft_printlong(t_mything *mylist);
void					ft_getlisi(t_mything *mylist, struct stat statisics,
						t_tots *total);
int						ft_islink(const char *pname);
void					ft_gettime(t_mything *mylist, struct stat statistics);
t_mything				**ft_setarray(t_mything **ptrarray, t_tots *total);
t_mything				**ft_setarray(t_mything **ptrarray, t_tots *total);
void					ft_printlink(char *path, t_mything *mylist);
t_mything				*ft_sortedmerge_t(t_mything *fh,
						t_mything *bh, unsigned char c);
void					ft_printdate(t_mything *mylist);
void					ft_checkspacing(int n);
void					ft_checkspacing_R(int n);

#endif
