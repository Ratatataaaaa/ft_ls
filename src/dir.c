/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:10:10 by cwing             #+#    #+#             */
/*   Updated: 2020/03/09 20:19:39 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

static char         *get_full_name(char *path_name, char *name)
{
    char            *full_name;

    full_name = NULL;
    if ((full_name = ft_strnew(PATH_MAX)))
    {
        ft_strncpy(full_name, path_name, PATH_MAX);
        ft_strncat(full_name, "/", PATH_MAX);
        ft_strncat(full_name, name, PATH_MAX);
    }
    return (full_name);
}

static t_dir        *new_t_dir(char *name, char *path)
{
    t_stat          *stat_;
    t_dir           *new_elem;
    char            *full_name;

    stat_ = NULL;
    new_elem = NULL;
    full_name = get_full_name(path, name);
    if ((stat_ = malloc(sizeof(t_stat))) &&
        (new_elem = malloc(sizeof(t_dir))) &&
        (lstat(full_name, stat_) == 0))
    {
        new_elem->name = name;
        new_elem->links = stat_->st_nlink;
        new_elem->u_name = get_user_name(stat_->st_uid);
        new_elem->u_group = get_group(stat_->st_gid);
        new_elem->time_ = get_time(&stat_->st_ctimespec.tv_sec);
        new_elem->chmod = get_chmod(stat_->st_mode);
        new_elem->next = NULL;
        new_elem->size = stat_->st_size;
    }
    else
    {
        ft_memdel((void**)&stat_);
        ft_memdel((void**)&new_elem);
    }
    ft_memdel((void**)&full_name);
    ft_memdel((void**)&stat_);
    return (new_elem);
}

static void         push_back(t_dir *head, t_dir *new_elem)
{
    if (head && new_elem)
    {
        while (head->next != NULL)
        {
            head = head ->next;
        }
        head->next = new_elem;
        new_elem = NULL;
    }
}

void                free_t_dir(t_dir **src)
{
    t_dir           *head;
    t_dir           *to_del;

    head = *src;
    while (head)
    {
        to_del = head;
        ft_memdel((void**)&head->chmod);
        ft_memdel((void**)&head->u_group);
        ft_memdel((void**)&head->u_name);
        head = head->next;
        ft_memdel((void**)&head);
    }
}

t_dir               *get_dir_list(char *path)
{
    t_dir           *head;
    t_dir           *new_e;
    DIR             *dir;
    t_dirent        *dirent_;

    head = NULL;
    if ((dir = opendir(path)) != NULL)
    {
        while ((dirent_ = readdir(dir)))
        {
            if (head == NULL && (head = new_t_dir(dirent_->d_name, path)))
                continue;
            else 
            {
                if ((new_e = new_t_dir(dirent_->d_name, path)))
                    push_back(head, new_e);
                else
                    free_t_dir(&head);
            }
        }
    }
    closedir(dir);
    return (head);
}