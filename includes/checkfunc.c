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
	if (n < 16)
		n = 16 - n;
	else
		n = n - 16;
	while (n-- > 0)
		ft_putchar(' ');
}

void		ft_checkflags(int *c, int *ptri, int x, char **argv)
{
	if (argv[*ptri][x] == 'a' && !(*c & FLAG_A))
		*c += FLAG_A;
	else if (argv[*ptri][x] == 'l' && !(*c & FLAG_L))
		*c += FLAG_L;
	else if (argv[*ptri][x] == 'r' && !(*c & FLAG_REV))
		*c += FLAG_REV;
	else if (argv[*ptri][x] == 'R' && !(*c & FLAG_R))
		*c += FLAG_R;
	else if (argv[*ptri][x] == 't' && !(*c & FLAG_T))
		*c += FLAG_T;
	else if (argv[*ptri][x] == 'A' && !(*c & FLAG_AL))
		*c += FLAG_AL;
	else if (argv[*ptri][x] == 'G' && !(*c & FLAG_AL))
		*c += FLAG_G;
	else if (argv[*ptri][x] == 'p' && !(*c & FLAG_P))
		*c += FLAG_P;
	else if (argv[*ptri][x] == 'f' && !(*c & FLAG_F))
	{
		*c += FLAG_F;
		*c += FLAG_A;
	}

}
