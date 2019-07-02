/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 11:07:53 by nreddy            #+#    #+#             */
/*   Updated: 2019/06/03 13:50:47 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_mkstr(char *c, long int n, int len)
{
	int m;

	m = 0;
	c[len] = '\0';
	len--;
	if (n < 0)
	{
		n *= -1;
		m = 1;
	}
	while (len >= 0)
	{
		c[len] = (n % 10 + 48);
		n = n / 10;
		len--;
	}
	if (m == 1)
		c[0] = '-';
	return (c);
}

static int		ft_itol(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (++len);
}

char			*ft_itoa(int n)
{
	int			len;
	char		*c;
	long int	num;

	num = n;
	len = ft_itol(num);
	if (!(c = (char	*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	return (ft_mkstr(c, num, len));
}
