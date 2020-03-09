/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 02:22:00 by cwing             #+#    #+#             */
/*   Updated: 2020/03/09 14:36:28 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

t_dir               *new_t_dir(char *name)
{
    t_stat          *stat_;
    t_dir           *new_elem;

    stat_ = NULL;
    new_elem = NULL;
    if ((stat_ = malloc(sizeof(t_stat))) &&
        (new_elem = malloc(sizeof(t_dir))) &&
        (lstat(get_full_name(get_dir_name(), name), stat_) == 0))
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
        ft_memdel((void**)stat_);
        ft_memdel((void**)new_elem);
    }
    return (new_elem);
}

void                push_back(t_dir *head, t_dir *new_elem)
{
    if (!head && !new_elem)
    {
        while (head->next != NULL)
        {
            head = head ->next;
        }
        head->next = new_elem;
    }
    new_elem = NULL;
}

void                free_t_dir(t_dir *head)
{

}

t_dir               *get_dir_list(char *path)
{
    t_dir           *head;
    t_dir           *new_e;
    DIR             *dir;
    t_dirent        *dirent_;

    head = NULL;
    if ((dir = opendir(get_dir_name())) != NULL)
    {
        while ((dirent_ = readdir(dir)))
        {
            if (head == NULL && (head = new_t_dir(dirent_->d_name)))
                continue;
            else 
            {
                if ((new_e = new_t_dir(dirent_->d_name)))
                    push_back(head, new_e);
                else
                    free_t_dir(head);
            }
        }
    }
    return (head);
}

int                 main(int argc, char **argv)
{
    t_dir           *head;

    head = get_dir_list(get_dir_name());
    while (head)
    {
        printf("%10s%4d%6s%6s%7lld %.12s %s\n", head->chmod, head->links,
        head->u_name, head->u_group, head->size, head->time_, head->name);
        head = head->next;
    }
    // {
    //     t_dir           *dir;
    //     DIR             *dirr;
    //     struct dirent   *dir_d;
    //     struct stat     *stat_d;

    //     dir = malloc(sizeof(t_dir));
    //     stat_d = malloc(sizeof(stat));
    //     dir_d = NULL;
    //     if ((dirr = opendir(get_dir_name())) == NULL)
    //     {
    //         ft_putstr("Error DIR get dir ptr\n");
    //     }

    //     while ((dir_d = readdir(dirr)))
    //     {
    //         lstat(get_full_name(get_dir_name(), dir_d->d_name), stat_d);
    //         printf("%10s%4d%6s%6s%7lld %.12s %s\n", get_chmod(stat_d->st_mode), stat_d->st_nlink,
    //         get_user_name(stat_d->st_uid), get_group(stat_d->st_gid), stat_d->st_size, get_time(&stat_d->st_ctimespec.tv_sec), dir_d->d_name);


    //         // printf("Hard links: %d\n", stat_d->st_nlink);
    //         // printf("Chmod: %s\n", get_chmod(stat_d->st_mode));
    //         // printf("Size file: %lld\n", stat_d->st_size);
    //         // printf("User id: %d\n", stat_d->st_gid);
    //         // printf("User name: %s\n", get_user_name(stat_d->st_uid));
    //         // printf("User gr name: %s\n", get_group(stat_d->st_gid));
    //         // printf("Time mod: %s", ctime(&stat_d->st_ctimespec.tv_sec));
    //         // ft_putchar('\n');
            
    //     }
    // }
    return (0);
}