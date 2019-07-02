/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:02:13 by nreddy            #+#    #+#             */
/*   Updated: 2019/05/28 15:53:19 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src1;
	char	*dst1;
	size_t	counter;

	counter = len;
	dst1 = (char *)dst;
	src1 = (char *)src;
	if (src < dst)
	{
		while (counter > 0)
		{
			counter--;
			dst1[counter] = src1[counter];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
