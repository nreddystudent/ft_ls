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

mything	*ft_listnew(char *content, size_t content_size)
{
	mything	*listn;

	if (!(listn = (mything *)malloc(sizeof(mything))))
		return (NULL);
	if (!(listn->d_name = (char *)malloc(content_size)))
		return (NULL);
	listn->next = NULL;
	if (content == NULL)
		listn->d_name = NULL;
	else
		ft_memcpy(listn->d_name, content, content_size);
	return (listn);
}
