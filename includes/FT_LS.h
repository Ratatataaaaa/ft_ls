/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FT_LS.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 02:13:55 by cwing             #+#    #+#             */
/*   Updated: 2020/03/10 18:30:38 by cwing            ###   ########.fr       */
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

typedef struct          s_slags
{
    char                l;
    char                R;
    char                a;
    char                r;
    char                t;
    char                u;
    char                f;
    char                g;
    char                d;
    char                G;
}                       t_flags;


typedef struct          s_dir
{
    char                *chmod;
    char                *u_name;
    char                *u_group;
    char                *time_mod;
    char                *time_get;
    char                *time_cre;
    char                *name;
    t_flags             *flags;
    off_t               size;
    nlink_t             links;
    struct s_dir        *next;
}                       t_dir;        
typedef struct stat     t_stat;
typedef struct dirent   t_dirent;

int                 get_stat(t_dir *dir);
t_dir               *get_dir_list(char *path, t_flags *flags);
char                *get_user_name(uid_t uid);
char                *get_group(gid_t gid);
char                *get_chmod(mode_t mode);
char                *get_time(time_t *time_);
void                free_t_dir(t_dir **src);
void                no_such_file(char *path);
t_flags             *get_flags(int argc, char **argv);
void                get_all_time(t_dir *elem, t_stat *stat_);
#endif