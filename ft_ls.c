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

int			ft_check_args(char **argv, int *ptri, int *c, int argc)
{
	int		x;

	while ((argv[*ptri][0] == '-') && (*ptri < argc))
	{
		x = 0;
		while (argv[*ptri][x])
		{
			if (argv[*ptri][x + 1] == '-' && argv[*ptri + 1] != NULL)
				return (*ptri + 1);
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
	int				c;
	char			*multif[argc];
	int				flagi[2];

	i = 0;
	if (argv[1] != NULL)
		i = 1;
	c = 0;
	i = ft_check_args(argv, &i, &c, argc);
	flagi[0] = c;
	flagi[1] = i;
	if (passread(flagi, argv, argc, multif) == 0)
		return (0);
	ft_ls(argc, argv, c, i);
	return (0);
}

void		ft_ls(int argc, char **argv, int c, int i)
{
	(void)argc;
	if (c & FLAG_MF)
		read_mf(argv, c, i);
	else
		ft_read(argv[i], c);
}
