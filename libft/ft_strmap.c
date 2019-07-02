/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 08:24:53 by nreddy            #+#    #+#             */
/*   Updated: 2019/05/28 16:20:11 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*c;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	c = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (c == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		c[i] = f(s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
