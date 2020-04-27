/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:41:31 by cwing             #+#    #+#             */
/*   Updated: 2020/04/27 17:58:55 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

void                no_such_file(char *path)
{
    ft_putstr("ft_ls: ");
    ft_putstr(path);
    ft_putstr(": No such file or directory\n");
}

void                get_all_time(t_dir *elem, t_stat *stat_)
{
    elem->time_cre = get_time(&stat_->st_ctimespec.tv_sec);
    elem->time_get = get_time(&stat_->st_atimespec.tv_sec);
    elem->time_mod = get_time(&stat_->st_mtimespec.tv_sec);
    elem->timecre_d = stat_->st_birthtimespec.tv_sec;
    elem->timeget_d = stat_->st_atimespec.tv_sec;
    elem->timemod_d = stat_->st_mtimespec.tv_sec;
}

void                check_names(t_list *head)
{
    DIR             *dir;

    dir = NULL;
    while (head)
    {
        dir = opendir((char*)(head->content));
        if (dir)
        {
			closedir(dir);
            head = head->next;
            continue;
        }
        else
        {
            no_such_file((char*)(head->content));
            head = head->next;
        }
    }
}

blkcnt_t            summ_blocks(t_dir *head)
{
    blkcnt_t        summ;

    summ = 0;
    while (head)
    {
        summ += head->blocks;
        head = head->next;
    }
    return (summ);
}