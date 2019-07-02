/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:30:38 by nreddy            #+#    #+#             */
/*   Updated: 2019/06/05 10:47:26 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	d;
	char	*e;
	size_t	i;

	d = (char)c;
	e = NULL;
	i = 0;
	if (ft_strlen(s) == 0 && d != '\0')
		return (NULL);
	if (d == '\0')
	{
		while (s[i] != '\0')
			i++;
		e = (char *)&s[i];
		return (e);
	}
	i = ft_strlen(s) - 1;
	while (s[i] != d)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	e = (char*)&s[i];
	return (e);
}
