/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 02:22:00 by cwing             #+#    #+#             */
/*   Updated: 2020/03/03 18:32:22 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

int                 main(int argc, char **argv)
{
    t_dir           *dir;
    DIR             *dirr;
    struct dirent   *dir_d;
    struct stat     *stat_d;
    struct passwd   *pass_t;
    struct group    *group_t;

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
        ft_putstr(dir_d->d_name);
        ft_putchar('\n');
        if (S_ISREG(stat_d->st_mode))
        {
            ft_putstr("File\n");
        }
        else if (S_ISDIR(stat_d->st_mode))
        {
            ft_putstr("Direction\n");
        }
        else if (S_ISLNK(stat_d->st_mode))
        {
            ft_putstr("Link\n");
        }
        else
        {
            ft_putstr("Xz who is it\n");
        }
        if (S_IRUSR & stat_d->st_mode)//Chek rule
                ft_putstr("User has rule for read!\n");
        printf("Hard links: %d\n", stat_d->st_nlink);
        printf("Size file: %lld\n", stat_d->st_size);
        printf("User id: %d\n", stat_d->st_gid);
        pass_t = getpwuid(stat_d->st_uid);
        printf("User name: %s\n", pass_t->pw_name);
        group_t = getgrgid(stat_d->st_gid);
        printf("User gr name: %s\n", group_t->gr_name);
        printf("Time mod: %s", ctime(&stat_d->st_ctimespec.tv_sec));
        ft_putchar('\n');
    }
    return (0);
}