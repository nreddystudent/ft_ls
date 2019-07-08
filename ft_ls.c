/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:38:30 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/04 16:30:05 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft/libft.h"

int		ft_check_args(char **argv, int *ptri, unsigned char *c)
{
	int		x;

	while (argv[*ptri][0] == '-')
	{
		x = 0;
		while (argv[*ptri][x] != '\0')
		{
			if (argv[*ptri][x] == 'a')
				*c += 1;
			if (argv[*ptri][x] == 'l')
				*c += 2;
			if (argv[*ptri][x] == 'r')
				*c += 4;
			if (argv[*ptri][x] == 'R')
				*c += 8;
			x++;
		}
		*ptri = *ptri + 1;
	}
	return (*ptri);
}

int		main(int argc, char **argv)
{
	int				i;
	unsigned char	c;

	i = 1;
	c = 0;
	if (argc == 1)
	{
		i = 0;
		ft_putstr("a dot");
		ft_ls(argc, argv, c, i);
	}
	i = ft_check_args(argv, &i, &c);
	if (argc - 1 - i > 0)
	{
		ft_putstr("multiple files");
		return (0);
	}
	ft_ls(argc, argv, c, i);
	return (0);
}