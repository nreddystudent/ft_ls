/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:00:01 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/19 09:00:13 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_ls.h"

void		ft_sortlist(t_mything **headref, int c)
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
	if (c & FLAG_T)
		*headref = ft_sortedmerge_t(fh, bh, c);
	else
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

t_mything	*ft_sortedmerge(t_mything *fh, t_mything *bh, int c)
{
	t_mything *result;

	result = NULL;
	if (fh == NULL)
		return (bh);
	else if (bh == NULL)
		return (fh);
	checkascii(c, fh, bh, &result);
	return (result);
}

t_mything	*ft_sortedmerge_t(t_mything *fh, t_mything *bh, int c)
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
	else if (fh->rawtime == bh->rawtime)
		ft_checknano(c, fh, bh, &result);
	else
	{
		result = bh;
		result->next = ft_sortedmerge_t(fh, bh->next, c);
	}
	return (result);
}

void		ft_checknano(int c, t_mything *fh, t_mything *bh,
			t_mything **result)
{
	if (!(c & FLAG_REV) && (fh->rawtimen > bh->rawtimen))
	{
		*result = fh;
		(*result)->next = ft_sortedmerge_t(fh->next, bh, c);
	}
	else if ((c & FLAG_REV) && (fh->rawtimen < bh->rawtimen))
	{
		*result = fh;
		(*result)->next = ft_sortedmerge_t(fh->next, bh, c);
	}
	else if (fh->rawtimen == bh->rawtimen)
		checkascii_t(c, fh, bh, result);
	else
	{
		*result = bh;
		(*result)->next = ft_sortedmerge_t(fh, bh->next, c);
	}
}
