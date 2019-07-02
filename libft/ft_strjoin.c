/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:37:39 by nreddy            #+#    #+#             */
/*   Updated: 2019/05/28 16:15:11 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	c = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (c == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		c[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		c[i] = *s2;
		i++;
		s2++;
	}
	c[i] = '\0';
	return (c);
}
