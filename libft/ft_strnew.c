/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 07:13:28 by nreddy            #+#    #+#             */
/*   Updated: 2019/05/28 16:30:35 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*c;

	c = (char *)malloc(size + 1);
	if (c == NULL)
		return (NULL);
	ft_bzero(c, size + 1);
	ft_memset(c, '\0', size);
	return (c);
}
