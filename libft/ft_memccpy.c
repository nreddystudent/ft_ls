/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:30:34 by nreddy            #+#    #+#             */
/*   Updated: 2019/05/28 15:44:39 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;
	unsigned char	c1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	c1 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		*dst1 = *src1;
		if (*src1 == c1)
			return (dst1 + 1);
		src1++;
		dst1++;
		i++;
	}
	return (NULL);
}
