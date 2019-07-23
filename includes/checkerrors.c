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

void	checkerrors(char *path)
{
	if (errno == 20)
		ft_putendl(path);
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

void	checkfiles(char **argv, int *i)
{
	while (argv[*i] != NULL)
	{
		opendir(argv[*i]);
		if (errno == 20)
		{
			errno = 0;
			ft_putstr(argv[*i++]);
			ft_putstr("   ");
			continue ;
		}
		*i += 1;
	}
}

void	checkillegalflag(char **argv, int *ptri, int x)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(argv[*ptri][x]);
	ft_putstr("\nusage: ls [-AGRaflnpt] [file ...]\n");
	exit(0);
}