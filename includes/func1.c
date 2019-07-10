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

void	ft_readr(char *path, unsigned char c,
		t_mything *mylist)
{
	char *str1;
	char *str2;

	while (mylist != NULL)
	{
		if ((ft_strcmp(".", mylist->d_name) == 0)
		|| (ft_strcmp("..", mylist->d_name) == 0))
		{
			mylist = mylist->next;
			continue ;
		}
		str1 = ft_strjoin("/", mylist->d_name);
		str2 = ft_strjoin(path, str1);
		free(str1);
		if ((ft_is_dir(str2) == 1))
		{
			ft_putstr(mylist->d_name);
			ft_putstr(":\n");
			ft_read(str2, c);
		}
		free(str2);
		mylist = mylist->next;
	}
}

void	ft_listdel(t_mything *mylist)
{
	t_mything *head;

	while (mylist != NULL)
	{
		head = mylist;
		mylist = mylist->next;
		free(head->d_name);
		free(head->group);
		free(head->user);
		free(head);
	}
}

void	ft_add_elements(t_mything *mylist)
{
	struct stat	statistics;

	stat(mylist->d_name, &statistics);
	ft_get_names(mylist, statistics);
	ft_get_fileperm(mylist, statistics);
}

void	ft_get_names(t_mything *mylist, struct stat statistics)
{
	struct group	*gruid;
	struct passwd	*uid;

	gruid = NULL;
	uid = NULL;
	uid = getpwuid(statistics.st_uid);
	gruid = getgrgid(statistics.st_gid);
	mylist->group = ft_strdup(gruid->gr_name);
	mylist->user = ft_strdup(uid->pw_name);
}

void	ft_get_fileperm(t_mything *mylist, struct stat statistics)
{
	mylist->permission[0] = S_ISDIR(statistics.st_mode) ? 'd' : '-';
	mylist->permission[1] = statistics.st_mode & S_IRUSR ? 'r' : '-';
	mylist->permission[2] = statistics.st_mode & S_IWUSR ? 'w' : '-';
	mylist->permission[3] = statistics.st_mode & S_IXUSR ? 'x' : '-';
	mylist->permission[4] = statistics.st_mode & S_IRGRP ? 'r' : '-';
	mylist->permission[5] = statistics.st_mode & S_IWGRP ? 'w' : '-';
	mylist->permission[6] = statistics.st_mode & S_IXGRP ? 'x' : '-';
	mylist->permission[7] = statistics.st_mode & S_IROTH ? 'r' : '-';
	mylist->permission[8] = statistics.st_mode & S_IWOTH ? 'w' : '-';
	mylist->permission[9] = statistics.st_mode & S_IXOTH ? 'x' : '-';
}
