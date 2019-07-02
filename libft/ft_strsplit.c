/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 08:15:43 by nreddy            #+#    #+#             */
/*   Updated: 2019/06/05 11:43:45 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcount(char const *s, char c)
{
	int		wcount;

	wcount = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
			wcount++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (wcount);
}

static int	ft_ccount(const char *s, char c, int *ccount, int *dcount)
{
	int		jcount;

	jcount = 0;
	while (s[*ccount] == c)
		*ccount += 1;
	*dcount = *ccount;
	while (s[*ccount] != c && s[*ccount] != '\0')
	{
		jcount++;
		*ccount += 1;
	}
	return (jcount);
}

char		**ft_strsplit(char const *s, char c)
{
	struct s_var a;

	if (s == NULL)
		return ((char **)NULL);
	a.wcount = 0;
	a.ccount = 0;
	a.jcount = 0;
	a.dcount = 0;
	a.o = 0;
	a.i = &a.ccount;
	a.h = &a.dcount;
	a.wcount = ft_strcount(s, c);
	if (!(a.a = (char **)malloc(sizeof(char *) * (a.wcount + 1))))
		return (NULL);
	while (a.wcount > 0)
	{
		a.jcount = ft_ccount(s, c, a.i, a.h);
		a.a[a.o] = ft_strsub(s, a.dcount, a.jcount);
		a.o++;
		a.wcount--;
	}
	a.a[a.o] = NULL;
	return (a.a);
}
