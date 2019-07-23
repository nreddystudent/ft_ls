/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setelements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:00:20 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/19 09:00:21 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_ls.h"

void	ft_add_elements(t_mything *mylist, char *path, t_tots *total, int c)
{
	struct stat	statistics;
	char		*temp;
	char		*rpath;

	temp = ft_strjoin(path, "/");
	rpath = ft_strjoin(temp, mylist->d_name);
	if (ft_islink(rpath))
	{
		lstat(rpath, &statistics);
	}
	else
		stat(rpath, &statistics);
	ft_get_fileperm(mylist, statistics, rpath);
	ft_getlisi(mylist, statistics, total);
	ft_get_names(mylist, statistics, c);
	ft_gettime(mylist, statistics);
	free(temp);
	free(rpath);
}

void	ft_get_fileperm(t_mything *mylist, struct stat statistics, char *path)
{
	mylist->permission[0] = (ft_is_dir(path)) ? 'd' : '-';
	if (ft_islink(path))
		mylist->permission[0] = 'l';
	mylist->permission[1] = statistics.st_mode & S_IRUSR ? 'r' : '-';
	mylist->permission[2] = statistics.st_mode & S_IWUSR ? 'w' : '-';
	mylist->permission[3] = statistics.st_mode & S_IXUSR ? 'x' : '-';
	if (statistics.st_mode & S_ISUID)
		mylist->permission[3] = mylist->permission[3] == 'x' ? 's' : 'S';
	mylist->permission[4] = statistics.st_mode & S_IRGRP ? 'r' : '-';
	mylist->permission[5] = statistics.st_mode & S_IWGRP ? 'w' : '-';
	mylist->permission[6] = statistics.st_mode & S_IXGRP ? 'x' : '-';
	if (statistics.st_mode & S_ISGID)
		mylist->permission[6] = mylist->permission[6] == 'x' ? 's' : 'S';
	mylist->permission[7] = statistics.st_mode & S_IROTH ? 'r' : '-';
	mylist->permission[8] = statistics.st_mode & S_IWOTH ? 'w' : '-';
	mylist->permission[9] = statistics.st_mode & S_IXOTH ? 'x' : '-';
	if (statistics.st_mode & S_ISVTX)
		mylist->permission[9] = mylist->permission[9] == 'x' ? 't' : 'T';
	mylist->permission[10] = '\0';
}

void	ft_getlisi(t_mything *mylist, struct stat statisics, t_tots *total)
{
	mylist->nlink = statisics.st_nlink;
	mylist->filesize = statisics.st_size;
	total->total += statisics.st_blocks;
}

void	ft_get_names(t_mything *mylist, struct stat statistics, int c)
{
	struct group	*gruid;
	struct passwd	*uid;

	gruid = NULL;
	uid = NULL;
	mylist->user = NULL;
	mylist->group = NULL;
	if (!(uid = getpwuid(statistics.st_uid)) || c & FLAG_N)
		mylist->user = ft_itoa(statistics.st_uid);
	if (!(gruid = getgrgid(statistics.st_gid)) || c & FLAG_N)
		mylist->group = ft_itoa(statistics.st_gid);
	if (!(mylist->group) && !(c & FLAG_N))
		mylist->group = ft_strdup(gruid->gr_name);
	if (!(mylist->user) && !(c & FLAG_N))
		mylist->user = ft_strdup(uid->pw_name);
}

void	ft_gettime(t_mything *mylist, struct stat statistics)
{
	char		*date;
	int			i;
	int			x;

	i = 4;
	x = 0;
	date = ft_strdup(ctime(&statistics.st_mtime));
	while (i < 16)
		mylist->date[x++] = date[i++];
	mylist->date[12] = '\0';
	mylist->rawtime = statistics.st_mtime;
	mylist->rawtimen = statistics.st_mtimespec.tv_nsec;
	free(date);
}
