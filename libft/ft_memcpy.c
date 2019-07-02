/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:03:19 by nreddy            #+#    #+#             */
/*   Updated: 2019/06/03 16:24:55 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst1;
	const char	*src1;
	size_t		i;

	dst1 = (char *)dst;
	src1 = (const char *)src;
	i = 0;
	if (n == 0)
		return ((void*)dst1);
	if (dst == NULL && src == NULL)
		return ((void*)dst1);
	while (i < n)
	{
		*dst1++ = *src1++;
		i++;
	}
	return (dst);
}
