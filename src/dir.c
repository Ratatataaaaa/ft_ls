/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:10:10 by cwing             #+#    #+#             */
/*   Updated: 2020/03/04 17:28:23 by cwing            ###   ########.fr       */
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

t_dir               *get_dir(char *path)
{
    return (NULL);
}