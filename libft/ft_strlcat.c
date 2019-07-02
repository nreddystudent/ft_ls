/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 09:02:30 by nreddy            #+#    #+#             */
/*   Updated: 2019/05/28 16:18:00 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		srclen;
	size_t		dstlen;
	size_t		left;

	srclen = ft_strlen(src);
	dstlen = ft_strnlen(dst, dstsize);
	left = dstsize - dstlen;
	if (dstsize == dstlen)
		return (srclen + dstlen);
	if (srclen < left)
	{
		ft_memcpy(dst + dstlen, src, srclen + 1);
	}
	else
	{
		ft_memcpy(dst + dstlen, src, dstsize + 1);
		dst[dstsize - 1] = '\0';
	}
	return (dstlen + srclen);
}
