/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:23:33 by nreddy            #+#    #+#             */
/*   Updated: 2019/05/23 14:26:56 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char			*s1;
	size_t					count;
	unsigned char			c1;

	c1 = (unsigned char)c;
	s1 = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		if (*s1 == c1)
		{
			return (s1);
		}
		count++;
		s1++;
	}
	return (NULL);
}
