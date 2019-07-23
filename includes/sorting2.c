/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 10:42:47 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/23 10:42:48 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_ls.h"

void	checkascii_t(int c, t_mything *fh, t_mything *bh, t_mything **result)
{
	if (!(c & FLAG_REV) && (ft_strcmp(fh->d_name, bh->d_name)) < 0)
	{
		*result = fh;
		(*result)->next = ft_sortedmerge_t(fh->next, bh, c);
	}
	else if ((c & FLAG_REV) && (ft_strcmp(fh->d_name, bh->d_name)) > 0)
	{
		*result = fh;
		(*result)->next = ft_sortedmerge_t(fh->next, bh, c);
	}
	else
	{
		*result = bh;
		(*result)->next = ft_sortedmerge_t(fh, bh->next, c);
	}
}

void	checkascii(int c, t_mything *fh, t_mything *bh, t_mything **result)
{
	if (!(c & FLAG_REV) && (ft_strcmp(fh->d_name, bh->d_name)) < 0)
	{
		*result = fh;
		(*result)->next = ft_sortedmerge(fh->next, bh, c);
	}
	else if ((c & FLAG_REV) && (ft_strcmp(fh->d_name, bh->d_name)) > 0)
	{
		*result = fh;
		(*result)->next = ft_sortedmerge(fh->next, bh, c);
	}
	else
	{
		*result = bh;
		(*result)->next = ft_sortedmerge(fh, bh->next, c);
	}
}
