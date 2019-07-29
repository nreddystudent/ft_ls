/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:00:27 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/19 09:00:29 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_ls.h"

void		ft_checkspacing(int n)
{
	int i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	if (i < 8)
		i = 8 - i;
	else
		i = i - 8;
	while (i-- > 0)
		ft_putchar(' ');
}

int			ft_is_dir(const char *pname)
{
	struct stat s;

	stat(pname, &s);
	return (S_ISDIR(s.st_mode));
}

int			ft_islink(const char *pname)
{
	struct stat s;

	lstat(pname, &s);
	return (S_ISLNK(s.st_mode));
}

void		ft_checkspacing_r(int n)
{
	(void)n;
	ft_putchar('\n');
}

void		ft_checkflags(int *c, int *ptri, int x, char **argv)
{
	if ((argv[*ptri][x] == 'a' || argv[*ptri][x] == 'f') && !(*c & FLAG_A))
		*c += FLAG_A;
	else if ((argv[*ptri][x] == 'l' || argv[*ptri][x] == 'n') && !(*c & FLAG_L))
		*c += FLAG_L;
	else if (argv[*ptri][x] == 'r' && !(*c & FLAG_REV))
		*c += FLAG_REV;
	else if (argv[*ptri][x] == 'R' && !(*c & FLAG_R))
		*c += FLAG_R;
	else if (argv[*ptri][x] == 't' && !(*c & FLAG_T))
		*c += FLAG_T;
	else if (argv[*ptri][x] == 'A' && !(*c & FLAG_AL))
		*c += FLAG_AL;
	else if (argv[*ptri][x] == 'G' && !(*c & FLAG_G))
		*c += FLAG_G;
	else if (argv[*ptri][x] == 'p' && !(*c & FLAG_P))
		*c += FLAG_P;
	else if (argv[*ptri][x] == 'f' && !(*c & FLAG_F))
		*c += FLAG_F;
	else if (argv[*ptri][x] == 'n' && !(*c & FLAG_N))
		*c += FLAG_N;
	else if (ft_checksetflag(argv[*ptri][x]) == 1)
		return ;
	else if ((x > 1 && argv[*ptri][x] == '-')
	|| (ft_checksetflag(argv[*ptri][x]) == 0 && x > 0 && argv[*ptri][1] != '-'))
		checkillegalflag(argv, ptri, x);
}
