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

void ft_printlink(char *path, t_mything *mylist)
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
