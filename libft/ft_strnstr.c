/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:37:55 by nreddy            #+#    #+#             */
/*   Updated: 2019/05/28 16:36:41 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		count;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while ((i < len) && haystack[i] != '\0')
	{
		count = 0;
		while (haystack[i + count] == needle[count])
		{
			if ((i + count) > len)
				return (NULL);
			if (needle[count + 1] == '\0')
				return ((char*)haystack + i);
			count++;
		}
		i++;
	}
	return (NULL);
}
