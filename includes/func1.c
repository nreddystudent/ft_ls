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
	char *str1;
	char *str2;

	while (mylist != NULL)
	{
		if ((ft_strcmp(".", mylist->d_name) == 0)
		|| (ft_strcmp("..", mylist->d_name) == 0))
		{
			mylist = mylist->next;
			continue ;
		}
		str1 = ft_strjoin("/", mylist->d_name);
		str2 = ft_strjoin(path, str1);
		free(str1);
		if ((ft_is_dir(str2) == 1))
		{
			ft_putstr(mylist->d_name);
			ft_putstr(":\n");
			ft_read(str2, c);
		}
		free(str2);
		mylist = mylist->next;
	}
}

void	ft_listdel(t_mything *mylist)
{
	t_mything *head;

	while (mylist != NULL)
	{
		head = mylist;
		mylist = mylist->next;
		free(head);
	}
}
