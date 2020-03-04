/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 02:22:00 by cwing             #+#    #+#             */
/*   Updated: 2020/03/04 16:04:44 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

int                 main(int argc, char **argv)
{
    t_dir           *dir;
    DIR             *dirr;
    struct dirent   *dir_d;
    struct stat     *stat_d;

    dir = malloc(sizeof(t_dir));
    stat_d = malloc(sizeof(stat));
    dir_d = NULL;
    if ((dirr = opendir(get_dir_name())) == NULL)
    {
        ft_putstr("Error DIR get dir ptr\n");
    }

    while ((dir_d = readdir(dirr)))
    {
        lstat(get_full_name(get_dir_name(), dir_d->d_name), stat_d);
        printf("%10s%4d%6s%6s%7lld %.12s %s\n", get_chmod(stat_d->st_mode), stat_d->st_nlink,
        get_user_name(stat_d->st_uid), get_group(stat_d->st_gid), stat_d->st_size, get_time(&stat_d->st_ctimespec.tv_sec), dir_d->d_name);


        // printf("Hard links: %d\n", stat_d->st_nlink);
        // printf("Chmod: %s\n", get_chmod(stat_d->st_mode));
        // printf("Size file: %lld\n", stat_d->st_size);
        // printf("User id: %d\n", stat_d->st_gid);
        // printf("User name: %s\n", get_user_name(stat_d->st_uid));
        // printf("User gr name: %s\n", get_group(stat_d->st_gid));
        // printf("Time mod: %s", ctime(&stat_d->st_ctimespec.tv_sec));
        // ft_putchar('\n');
        
    }
    return (0);
}