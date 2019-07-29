/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 09:24:33 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/23 09:24:35 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_ls.h"

void	printtotal(t_tots total)
{
	ft_putstr("total ");
	ft_putnbr(total.total);
	ft_putchar('\n');
}

void	ft_checkspacing_s(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 14)
		i = 14 - i;
	else
		i = i - 14;
	while (i-- > 0)
		ft_putchar(' ');
}

void	ft_print_long_file(char *file, int flags)
{
	t_mything	*filedetail;
	t_tots		filenum;

	filenum.flags = flags;
	filedetail = ft_listnew(file, "./", &filenum);
	ft_printlong(filedetail);
	ft_putstr(" ");
	ft_putendl(file);
	ft_listdel(filedetail);
}
