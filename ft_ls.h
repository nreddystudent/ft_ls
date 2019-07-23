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
# define MAXPATHLEN 1024
# define FLAG_A		1
# define FLAG_L		2
# define FLAG_REV	4
# define FLAG_R		8
# define FLAG_T		32
# define FLAG_MF	64
# define FLAG_AL	128
# define FLAG_G		256
# define FLAG_N		512
# define FLAG_F		1024
# define FLAG_P		2048

typedef	struct			s_mystuff
{
	char				*d_name;
	char				*user;
	char				*group;
	char				permission[12];
	int					nlink;
	int					filesize;
	char				date[13];
	time_t				rawtime;
	time_t				rawtimen;
	struct s_mystuff	*next;
}						t_mything;

typedef struct			s_tots
{
	int					total;
	int					flags;
}						t_tots;

void					ft_recursion(char *argv, struct dirent *ptrf);
t_mything				*ft_listnew(char *content, char *path, t_tots *total);
int						ft_is_dir(const char *pname);
t_mything				*ft_listcreate(t_mything **myarray, struct dirent *ptrf,
						char *path, t_tots *total);
void					ft_printlist(t_mything *mylist, int c,
						t_tots total, char *path);
void					ft_ls(int argc, char **argv, int c, int i);
void					ft_read(char *path, int c);
void					ft_listadd(t_mything **list, t_mything *new);
void					ft_sortlist(t_mything **headref, int c);
void					frontbacksplit(t_mything *head,
						t_mything **fh, t_mything **bh);
t_mything				*ft_sortedmerge(t_mything *fh,
						t_mything *bh, int c);
void					ft_readr(char *path,
						int c, t_mything *mylist);
void					ft_listdel(t_mything *mylist);
void					ft_add_elements(t_mything *mylist, char *path,
						t_tots *total, int c);
void					ft_get_names(t_mything *mylist, struct stat statistics
						,int c);
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
						t_mything *bh, int c);
void					ft_printdate(t_mything *mylist);
void					ft_checkspacing(int n);
void					ft_checkspacing_r(int n);
void					ft_checknano(int c, t_mything *fh,
						t_mything *bh, t_mything **result);
void					ft_putdir(char *str);
void					ft_checkflags(int *c, int *ptri
						,int x, char **argv);
int						ft_checkextra(char *filename, int c);
void					ft_putextra(t_mything *mylist, int c);
void					checkerrors(char *path);
void					printtotal(t_tots total);
void					checkrecursion(char *path, int c, t_mything **ptrarray);
void					read_mf(char **argv, int c);
void					checkfiles(char **argv, int *i);
void					checkascii(int c, t_mything *fh, t_mything *bh
						, t_mything **result);
void					checkascii_t(int c, t_mything *fh, t_mything *bh
						, t_mything **result);

#endif
