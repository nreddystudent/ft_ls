/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:06:08 by nreddy            #+#    #+#             */
/*   Updated: 2019/06/05 10:32:00 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*c;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (c == NULL)
		return (NULL);
	while (len > 0)
	{
		c[i] = s[start];
		start++;
		i++;
		len--;
	}
	c[i] = '\0';
	return (c);
}
