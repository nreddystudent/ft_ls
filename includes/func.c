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

mything	*ft_listnew(char *content)
{
	mything	*listn;

	listn = NULL;
	if (!(listn = (mything *)malloc(sizeof(mything))))
		return (NULL);
	if (!(listn->d_name = ft_strdup(content)))
		return (NULL);
	listn->next = NULL;
	return (listn);
}

void	ft_listadd(mything **list, mything *new)
{
	new->next = *list;
	*list = new;
}

void	ft_sortlist(mything **headref)
{
	mything	*head;
	mything *fh;
	mything *bh;

	head = *headref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	frontbacksplit(head, &fh, &bh);
	ft_sortlist(&fh);
	ft_sortlist(&bh);
	*headref = ft_sortedmerge(fh, bh);
}

void	frontbacksplit(mything *head, mything **fh, mything **bh)
{
	mything *fast;
	mything *slow;

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

mything	*ft_sortedmerge(mything *fh, mything *bh)
{
	mything *result;

	result = NULL;
	if (fh == NULL || bh == NULL)
		return (NULL);
	if (ft_strcmp(fh->d_name, bh->d_name) < 0)
	{
		result = fh;
		result->next = ft_sortedmerge(fh->next, bh);
	}
	else
	{
		result = bh;
		result->next = ft_sortedmerge(fh, bh->next);
	}
	return(result);
}