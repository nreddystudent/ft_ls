/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:08:55 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/08 15:08:56 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"
#include "../libft/libft.h"

void	ft_readr(char *path, unsigned char c)
{
	DIR *file;
	struct dirent *files;

	file = opendir(path);
	while(!(files = readdir(file)))
	{
		if (!(ft_strcmp(".", files->d_name)) && !(ft_strcmp("..", files->d_name)))
			continue ;
		if (ft_is_dir(files->d_name) == 1)
		{
			ft_read(ft_strjoin("./", files->d_name), c);
			ft_putstr("see");
		}
	}
	closedir(file);
}