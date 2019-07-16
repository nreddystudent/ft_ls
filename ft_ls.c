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

void		ft_checkflags(unsigned char *c, int *ptri, int x, char **argv)
{
	if (argv[*ptri][x] == 'a' && !(*c & FLAG_A))
		*c += FLAG_A;
	if (argv[*ptri][x] == 'l' && !(*c & FLAG_L))
		*c += FLAG_L;
	if (argv[*ptri][x] == 'r' && !(*c & FLAG_REV))
		*c += FLAG_REV;
	if (argv[*ptri][x] == 'R' && !(*c & FLAG_R))
		*c += FLAG_R;
	if (argv[*ptri][x] == 't' && !(*c & FLAG_T))
		*c += FLAG_T;
}

int			ft_check_args(char **argv, int *ptri, unsigned char *c, int argc)
{
	int		x;

	while ((argv[*ptri][0] == '-') && (*ptri < argc))
	{
		x = 0;
		while (argv[*ptri][x])
		{
			if (argv[*ptri][x + 1] == '-')
				return(*ptri + 1);
			ft_checkflags(c, ptri, x, argv);
			x++;
		}
		if (argv[*ptri + 1] == NULL)
		{
			*c += 16;
			break ;
		}
		*ptri = *ptri + 1;
	}
	return (*ptri);
}

void		ft_sortarray(char **files)
{
	int		i;
	char	*namedir;

	i = 0;
	while ((files[i] != NULL) && (files[i + 1] != NULL))
	{
		if (ft_strcmp(files[i], files[i + 1]) < 0 ||
		(ft_strcmp(files[i], files[i + 1]) == 0))
			i++;
		else
		{
			namedir = files[i];
			files[i] = files[i + 1];
			files[i + 1] = namedir;
			i = 0;
		}
	}
}

void		ft_multifile(char **multif, int argc, int i, char **argv)
{
	int		x;

	x = 0;
	while (i < argc)
		multif[x++] = argv[i++];
	multif[x] = NULL;
	ft_sortarray(multif);
}

int			main(int argc, char **argv)
{
	int				i;
	unsigned char	c;
	char			*multif[argc];

	i = 0;
	if (argv[1] != NULL)
		i = 1;
	c = 0;
	i = ft_check_args(argv, &i, &c, argc);
	if ((argc == 1) || (c & 16))
	{
		ft_read(".", c);
		return (0);
	}
	if (argc - 1 - i > 0)
	{
		ft_multifile(multif, argc, i, argv);
		c += FLAG_MF;
		ft_ls(argc, multif, c, i);
		return (0);
	}
	ft_ls(argc, argv, c, i);
	return (0);
}
