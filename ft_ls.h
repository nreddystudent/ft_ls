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

typedef	struct			s_mystuff
{
	char				*d_name;
	struct s_mystuff	*next;
}						t_mything;

void					ft_recursion(char *argv, struct dirent *ptrf);
t_mything				*ft_listnew(char *content);
int						ft_is_dir(const char *pname);
t_mything				*ft_listcreate(t_mything *mylist,
						t_mything *new, struct dirent *ptrf);
void					ft_printlist(t_mything *mylist);
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


#endif
