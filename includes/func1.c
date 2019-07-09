/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:08:55 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/08 15:08:56 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"
#include "../libft/libft.h"

void	ft_readr(char *path, unsigned char c,
		t_mything *mylist)
{
	while (mylist != NULL)
	{
		if ((ft_strcmp(".", mylist->d_name) == 0)
		|| (ft_strcmp("..", mylist->d_name) == 0))
		{
			mylist = mylist->next;
			continue ;
		}
		if ((ft_is_dir((ft_strjoin(path,
		ft_strjoin("/", mylist->d_name)))) == 1))
		{
			ft_putstr(mylist->d_name);
			ft_putstr(":\n");
			ft_read(ft_strjoin(path, ft_strjoin("/", mylist->d_name)), c);
		}
		mylist = mylist->next;
	}
}
