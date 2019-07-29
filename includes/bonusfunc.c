/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 08:37:42 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/23 08:37:43 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_ls.h"

int		ft_checkextra(char *filename, int c)
{
	if (!(c & FLAG_A) && (filename[0] == '.') && (!(c & FLAG_AL)))
		return (1);
	if (c & FLAG_AL && !(c & FLAG_A))
	{
		if ((ft_strcmp(".", filename) == 0)
		|| (ft_strcmp("..", filename) == 0))
			return (1);
	}
	return (0);
}

int		bgcolour(t_mything *mylist)
{
	if (ft_strchr(mylist->permission, 's')
	|| ft_strchr(mylist->permission, 't'))
	{
		ft_putstr("\e[30m");
		if (mylist->permission[3] == 's' || mylist->permission[3] == 't')
			ft_putstr("\033[0;41m");
		else if (mylist->permission[6] == 's' || mylist->permission[6] == 't')
			ft_putstr("\033[0;46m");
		else if (mylist->permission[9] == 's' || mylist->permission[9] == 't')
			ft_putstr("\033[0;45m");
		return (1);
	}
	return (0);
}

void	ft_putextra(t_mything *mylist, int c)
{
	int res;

	res = 0;
	if (c & FLAG_G)
		res = bgcolour(mylist);
	if ((res == 0 && c & FLAG_G))
	{
		if (mylist->permission[0] == 'd')
			ft_putstr("\033[0;34m");
		else if (mylist->permission[0] == 'l')
			ft_putstr("\033[0;35m");
		else if (mylist->permission[3] == 'x')
			ft_putstr("\033[0;31m");
	}
	if (res == 1)
		ft_putstr("\e[30m");
	ft_putstr(mylist->d_name);
	ft_putstr("\033[0m");
	if (mylist->permission[0] == 'd' && c & FLAG_P)
		ft_putchar('/');
}
