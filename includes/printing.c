/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:14:36 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/11 17:14:38 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_ls.h"

void	ft_checkspacing(int n)
{
	int i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	if (i < 6)
		i = 6 - i;
	else
		i = i - 6;
	while (i-- > 0)
		ft_putchar(' ');
}

void	ft_printlong(t_mything *mylist)
{
	ft_putstr(mylist->permission);
	ft_putstr("      ");
	ft_putnbr(mylist->nlink);
	ft_checkspacing(mylist->nlink);
	ft_putstr(mylist->user);
	ft_putstr("      ");
	ft_putstr(mylist->group);
	ft_putstr("      ");
	ft_putnbr(mylist->filesize);
	ft_checkspacing(mylist->filesize);
	ft_putstr(mylist->date);
	ft_putchar(' ');
}

void	ft_getlisi(t_mything *mylist, struct stat statisics, t_tots *total)
{
	mylist->nlink = statisics.st_nlink;
	mylist->filesize = statisics.st_size;
	total->total += statisics.st_blocks;
}

int		ft_islink(const char *pname)
{
	struct stat s;

	lstat(pname, &s);
	return (S_ISLNK(s.st_mode));
}

void	ft_gettime(t_mything *mylist, struct stat statistics)
{
	char		*date;
	int			i;
	int			x;

	i = 4;
	x = 0;
	date = ft_strdup(ctime(&statistics.st_mtime));
	while (i < 16)
		mylist->date[x++] = date[i++];
	mylist->date[12] = '\0';
	free(date);
}
