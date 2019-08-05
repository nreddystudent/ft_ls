/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setelements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:00:20 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/30 11:11:55 by nreddy           ###   ########.fr       */
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
		lstat(rpath, &statistics);
	else
		stat(rpath, &statistics);
	ft_get_fileperm(mylist->permission, statistics, rpath);
	ft_getlisi(mylist, statistics, total);
	ft_get_names(mylist, statistics, c);
	ft_gettime(mylist->date, statistics,
	&(mylist->rawtime), &(mylist->rawtimen));
	free(temp);
	free(rpath);
}

void	ft_get_fileperm(char *permission, struct stat statistics, char *path)
{
	permission[11] = '\0';
	setfirstpermission(permission, path);
	permission[1] = statistics.st_mode & S_IRUSR ? 'r' : '-';
	permission[2] = statistics.st_mode & S_IWUSR ? 'w' : '-';
	permission[3] = statistics.st_mode & S_IXUSR ? 'x' : '-';
	if (statistics.st_mode & S_ISUID)
		permission[3] = permission[3] == 'x' ? 's' : 'S';
	permission[4] = statistics.st_mode & S_IRGRP ? 'r' : '-';
	permission[5] = statistics.st_mode & S_IWGRP ? 'w' : '-';
	permission[6] = statistics.st_mode & S_IXGRP ? 'x' : '-';
	if (statistics.st_mode & S_ISGID)
		permission[6] = permission[6] == 'x' ? 's' : 'S';
	permission[7] = statistics.st_mode & S_IROTH ? 'r' : '-';
	permission[8] = statistics.st_mode & S_IWOTH ? 'w' : '-';
	permission[9] = statistics.st_mode & S_IXOTH ? 'x' : '-';
	if (statistics.st_mode & S_ISVTX)
		permission[9] = permission[9] == 'x' ? 't' : 'T';
	ft_extendedacl(path, permission);
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

void	ft_gettime(char *datem, struct stat statistics, time_t *rawtime
		, time_t *rawtimen)
{
	char		*date;
	int			i;
	int			x;

	i = 4;
	x = 0;
	date = ft_strdup(ctime(&statistics.st_mtime));
	while (i < 16)
		datem[x++] = date[i++];
	datem[12] = '\0';
	*rawtime = statistics.st_mtime;
	*rawtimen = statistics.st_mtimespec.tv_nsec;
	free(date);
}
