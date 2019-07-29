/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:14:36 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/19 09:00:37 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_ls.h"

void	ft_printlong(t_mything *mylist)
{
	ft_putstr(mylist->permission);
	ft_putstr(" ");
	ft_putnbr(mylist->nlink);
	ft_checkspacing(mylist->nlink);
	ft_putstr(mylist->user);
	ft_checkspacing_s(mylist->user);
	ft_putstr(mylist->group);
	ft_checkspacing_s(mylist->group);
	ft_putnbr(mylist->filesize);
	ft_checkspacing(mylist->filesize);
	ft_printdate(mylist);
	ft_putchar(' ');
}

void	ft_printlist(t_mything *mylist, int c,
						t_tots total, char *path)
{
	if (c & FLAG_L)
		printtotal(total);
	while (mylist != NULL)
	{
		if (c & FLAG_L)
			ft_printlong(mylist);
		if ((c & FLAG_G) || (c & FLAG_P))
			ft_putextra(mylist, c);
		else
			ft_putstr(mylist->d_name);
		if (mylist->permission[0] == 'l' && c & FLAG_L)
			ft_printlink(path, mylist);
		if (c & FLAG_L && mylist->next != NULL)
			ft_putchar('\n');
		else if (c & FLAG_R)
			ft_checkspacing_r(ft_strlen(mylist->d_name));
		else if (mylist->next != NULL)
			ft_putchar('\n');
		mylist = mylist->next;
	}
	ft_putchar('\n');
	if (c & FLAG_R || (c & FLAG_L && c & FLAG_R))
		ft_putchar('\n');
}

void	ft_printlink(char *path, t_mything *mylist)
{
	char		linkpath[MAXPATHLEN + 1];
	char		*pathtemp;
	char		*fullpath;

	pathtemp = ft_strjoin(path, "/");
	fullpath = ft_strjoin(pathtemp, mylist->d_name);
	ft_bzero(linkpath, MAXPATHLEN);
	readlink(fullpath, linkpath, MAXPATHLEN);
	ft_putstr(" -> ");
	ft_putstr(linkpath);
	free(pathtemp);
	free(fullpath);
}

void	ft_printdate(t_mything *mylist)
{
	char	*str;
	char	*times;

	str = mylist->date + 3;
	str[3] = '\0';
	ft_putstr(str);
	ft_putchar(' ');
	mylist->date[3] = '\0';
	ft_putstr(mylist->date);
	ft_putchar(' ');
	times = mylist->date + 7;
	ft_putstr(times);
}

void	ft_putdir(char *str)
{
	ft_putstr(str);
	ft_putstr(":\n");
}
