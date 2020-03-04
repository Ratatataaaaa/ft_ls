/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FT_LS.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 02:13:55 by cwing             #+#    #+#             */
/*   Updated: 2020/03/04 16:04:42 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <dirent.h>
# include <limits.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

// TO DELL
# include <stdio.h>

typedef struct      s_dir
{
    char            *name;
    char            *full_name;
    char            ch_mod[11];
    struct stat     *stat_dir;
}                   t_dir;        

char                *get_dir_name();
char                *get_full_name(char *path_name, char *name);
int                 get_stat(t_dir *dir);
t_dir               *get_dir(char *path);
char                *get_user_name(uid_t uid);
char                *get_group(gid_t gid);
char                *get_chmod(mode_t mode);
char                *get_time(time_t *time_);
#endif