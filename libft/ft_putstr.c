/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 06:39:55 by nreddy            #+#    #+#             */
/*   Updated: 2019/05/27 09:03:46 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(const char *s)
{
	int count;

	if (s == NULL)
		return ((void)NULL);
	count = 0;
	while (s[count] != '\0')
	{
		ft_putchar(s[count]);
		count++;
	}
}
