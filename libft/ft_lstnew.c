/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:57:50 by nreddy            #+#    #+#             */
/*   Updated: 2019/06/03 18:26:04 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*listn;

	listn = NULL;
	if (!(listn = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(listn->content = (void *)malloc(content_size)))
		return (NULL);
	listn->next = NULL;
	if (content == NULL)
	{
		listn->content_size = 0;
		listn->content = NULL;
	}
	else
	{
		listn->content_size = content_size;
		ft_memcpy(listn->content, content, content_size);
	}
	return (listn);
}
