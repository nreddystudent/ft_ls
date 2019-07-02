/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 08:50:41 by nreddy            #+#    #+#             */
/*   Updated: 2019/06/05 10:24:23 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;

	if (s1 == NULL || s2 == NULL)
		return ('\0');
	i = 0;
	i = ft_strncmp(s1, s2, n);
	if (i < 0 || i > 0)
		return (0);
	else
		return (1);
}
