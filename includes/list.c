/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:38:20 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/04 16:28:18 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_ls.h"

t_mything	*ft_listcreate(t_mything **myarray, struct dirent *ptrf, char *path,
			t_tots *total)
{
	if (myarray[0] == NULL)
	{
		myarray[0] = ft_listnew(ptrf->d_name, path, total);
		return (myarray[0]);
	}
	else
	{
		myarray[1] = ft_listnew(ptrf->d_name, path, total);
		ft_listadd(&myarray[0], myarray[1]);
		return (myarray[0]);
	}
}

t_mything	*ft_listnew(char *content, char *path, t_tots *total)
{
	t_mything	*listn;

	listn = NULL;
	if (!(listn = (t_mything *)malloc(sizeof(t_mything))))
		return (NULL);
	if (!(listn->d_name = ft_strdup(content)))
		return (NULL);
	listn->next = NULL;
	ft_add_elements(listn, path, total);
	return (listn);
}

void		ft_listadd(t_mything **list, t_mything *new)
{
	t_mything	*tail;

	tail = *list;
	if (*list == NULL)
		(*list)->next = new;
	else
	{
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = new;
	}
}

void		ft_listdel(t_mything *mylist)
{
	t_mything *head;

	while (mylist != NULL)
	{
		head = mylist;
		mylist = mylist->next;
		free(head->d_name);
		free(head->group);
		free(head->user);
		free(head);
	}
}
