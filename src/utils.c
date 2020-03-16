/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:41:31 by cwing             #+#    #+#             */
/*   Updated: 2020/03/16 20:26:31 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

void                no_such_file(char *path)
{
    printf("ls: %s: No such file or directory\n", path);
}

void                get_all_time(t_dir *elem, t_stat *stat_)
{
    elem->time_cre = get_time(&stat_->st_ctimespec.tv_sec);
    elem->time_get = get_time(&stat_->st_atimespec.tv_sec);
    elem->time_mod = get_time(&stat_->st_mtimespec.tv_sec);
}

