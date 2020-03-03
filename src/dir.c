/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:10:10 by cwing             #+#    #+#             */
/*   Updated: 2020/03/03 15:37:32 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

char                *get_dir_name()
{
    char            *name_dir;
    
    name_dir = NULL;
    if((name_dir = ft_strnew(PASS_MAX)) && getwd(name_dir))
        return (name_dir);
    else
        ft_putstr("Error get dir name.\n");
    return (name_dir);
}

char                *get_full_name(char *path_name, char *name)
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

int                 get_stat(t_dir *dir)
{
    struct stat     *stat_dir;

    if ((stat_dir = malloc(sizeof(stat))) &&
        ((lstat(dir->full_name, stat_dir) == 0)))
    {
        dir->stat_dir = stat_dir;
        return (1);
    }
    else
        return (0);
}

t_dir               *get_dir(char *path)
{
    t_dir           *dir;
    DIR             *dirr;
    struct dirent   *dir_d;

    dir = malloc(sizeof(t_dir));
    if ((dirr = opendir(get_dir_name())) == NULL)
    {
        ft_putstr("Error DIR get dir ptr\n");
    }

}