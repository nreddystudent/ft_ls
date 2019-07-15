/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:13:43 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/15 10:13:45 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_ls.h"

t_mything	**ft_setarray(t_mything **ptrarray, t_tots *total)
{
	t_mything			*new;
	t_mything			*ptrmystuff;

	ptrmystuff = NULL;
	new = NULL;
	ptrarray[0] = ptrmystuff;
	ptrarray[1] = new;
	total->total = 0;
	return (ptrarray);
}
