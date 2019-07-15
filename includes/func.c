/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:11:55 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/05 15:11:59 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"
#include "../libft/libft.h"

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
	new->next = *list;
	*list = new;
}

void		ft_sortlist(t_mything **headref, unsigned char c)
{
	t_mything	*head;
	t_mything	*fh;
	t_mything	*bh;

	head = *headref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	frontbacksplit(head, &fh, &bh);
	ft_sortlist(&fh, c);
	ft_sortlist(&bh, c);
	*headref = ft_sortedmerge(fh, bh, c);
}

void		frontbacksplit(t_mything *head, t_mything **fh, t_mything **bh)
{
	t_mything *fast;
	t_mything *slow;

	slow = head;
	fast = head->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*fh = head;
	*bh = slow->next;
	slow->next = NULL;
}

t_mything	*ft_sortedmerge(t_mything *fh, t_mything *bh, unsigned char c)
{
	t_mything *result;

	result = NULL;
	if (fh == NULL)
		return (bh);
	else if (bh == NULL)
		return (fh);
	if (!(c & FLAG_REV) && (ft_strcmp(fh->d_name, bh->d_name)) < 0)
	{
		result = fh;
		result->next = ft_sortedmerge(fh->next, bh, c);
	}
	else if ((c & FLAG_REV) && (ft_strcmp(fh->d_name, bh->d_name)) > 0)
	{
		result = fh;
		result->next = ft_sortedmerge(fh->next, bh, c);
	}
	else
	{
		result = bh;
		result->next = ft_sortedmerge(fh, bh->next, c);
	}
	return (result);
}
