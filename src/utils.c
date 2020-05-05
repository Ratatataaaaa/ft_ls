/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:41:31 by cwing             #+#    #+#             */
/*   Updated: 2020/05/03 21:53:26 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

void				no_such_file(char *path)
{
	ft_putstr("ft_ls: ");
	ft_putstr(path);
	ft_putstr(": No such file or directory\n");
}

void				get_all_time(t_dir *elem, t_stat *stat_)
{
	elem->time_cre = get_time(&stat_->st_ctime);
	elem->time_get = get_time(&stat_->st_atime);
	elem->time_mod = get_time(&stat_->st_mtime);
	elem->timecre_d = stat_->st_ctime;
	elem->timeget_d = stat_->st_atime;
	elem->timemod_d = stat_->st_mtime;
}

void				check_names(t_list *head, t_flags **flags)
{
	DIR				*dir;

	dir = NULL;
	while (head)
	{
		dir = opendir((char*)(head->content));
		if (dir)
			closedir(dir);
		else if (open_single_file((char*)(head->content), flags))
			ft_isdigit('A');
		else
			no_such_file((char*)(head->content));
		head = head->next;
	}
}

blkcnt_t			summ_blocks(t_dir *head)
{
	blkcnt_t		summ;

	summ = 0;
	while (head)
	{
		if (head->name[0] =='.')
		{
			head = head->next;
			continue;
		}
		summ += (head->blocks / 2);
		head = head->next;
	}
	return (summ);
}

int					open_single_file(char *path, t_flags **flags)
{
	t_dir			*single;

	single = NULL;
	if (path[0] == '/')
		single = new_t_dir(path, "", flags);
	else
		single = new_t_dir(path, "./", flags);
	if (single)
	{
		main_print(single);
		free_t_dir(&single);
		return (1);
	}
	return (0);
}
