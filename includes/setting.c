/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:13:43 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/15 10:13:45 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_ls.h"

t_mything	**ft_setarray(t_mything **ptrarray, t_tots *total)
{
	t_mything			*new;
	t_mything			*ptrmystuff;

	ptrmystuff = NULL;
	new = NULL;
	ptrarray[0] = ptrmystuff;
	ptrarray[1] = new;
	total->total = 0;
	return (ptrarray);
}

void		ft_printlink(char *path, t_mything *mylist)
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

t_mything	*ft_sortedmerge_t(t_mything *fh, t_mything *bh, unsigned char c)
{
	t_mything *result;

	result = NULL;
	if (fh == NULL)
		return (bh);
	else if (bh == NULL)
		return (fh);
	if (!(c & FLAG_REV) && (fh->rawtime > bh->rawtime))
	{
		result = fh;
		result->next = ft_sortedmerge_t(fh->next, bh, c);
	}
	else if ((c & FLAG_REV) && (fh->rawtime < bh->rawtime))
	{
		result = fh;
		result->next = ft_sortedmerge_t(fh->next, bh, c);
	}
	else
	{
		result = bh;
		result->next = ft_sortedmerge_t(fh, bh->next, c);
	}
	return (result);
}

void	ft_printdate(t_mything *mylist)
{
	char *str;
	char *times;
	
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