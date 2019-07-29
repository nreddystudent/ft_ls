/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerrors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 08:47:03 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/23 08:47:08 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"
#include "../libft/libft.h"

void	checkerrors(char *path, int flags)
{
	if (errno == 20)
	{
		checkfiles(&path, flags);
		ft_putchar('\n');
		return ;
	}
	else
	{
		ft_putstr("ls : ");
		ft_putstr(path);
		ft_putstr(":   ");
		perror(strerror(errno));
	}
	return ;
}

void	checkrecursion(char *path, int c, t_mything **ptrarray)
{
	if (c & FLAG_R)
		ft_readr(path, c, ptrarray[0]);
}

void	checkfiles(char **argv, int c)
{
	int i;
	DIR *file;

	i = 0;
	while (argv[i] != NULL)
	{
		file = opendir(argv[i]);
		if (errno == 20)
		{
			errno = 0;
			if (c & FLAG_L)
			{
				ft_print_long_file(argv[i++], c);
				continue ;
			}
			else
				ft_putstr(argv[i++]);
			ft_putstr("   ");
			continue ;
		}
		i += 1;	
		closedir(file);
	}

}

void	checkillegalflag(char **argv, int *ptri, int x)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(argv[*ptri][x]);
	ft_putstr("\nusage: ls [-AGRaflnpt] [file ...]\n");
	exit(0);
}

int		ft_checksetflag(char flag)
{
	if (flag == 'G' || flag == 'a' || flag == 'l' || flag == 'r' || flag == 'R'
	|| flag == 't' || flag == 'A' || flag == 'p' || flag == 'f'
	|| flag == 'n')
		return (1);
	return (0);
}
