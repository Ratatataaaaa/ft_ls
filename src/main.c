/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 02:22:00 by cwing             #+#    #+#             */
/*   Updated: 2020/02/22 06:55:02 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"
// to_del
#include <stdio.h>
#include <errno.h>
// https://www.ibm.com/developerworks/ru/library/au-unix-readdir/index.html
// end

int         open_dir(char *dir_name)
{
    DIR *dir = NULL;
    struct dirent entry;
    struct dirent *entryPtr = NULL;
    int retval = 0;
    unsigned count = 0;
    char pathName[PATH_MAX + 1];
 
    dir = opendir(dir_name);
    if( dir == NULL )
    {
        ft_putstr("Dir open error!\n");
        return 0;
    }
    retval = readdir_r( dir, &entry, &entryPtr );
    while( entryPtr != NULL ) 
    {
        struct stat entryInfo;
        if( ( strncmp( entry.d_name, ".", PATH_MAX ) == 0 ) ||
            ( strncmp( entry.d_name, "..", PATH_MAX ) == 0 ) )
        {
        retval = readdir_r( dir, &entry, &entryPtr );
        continue;
        }
        (void)ft_strncpy( pathName, dir_name, PATH_MAX );
        (void)ft_strncat( pathName, "/", PATH_MAX );
        (void)ft_strncat( pathName, entry.d_name, PATH_MAX );
         
        if( lstat( pathName, &entryInfo ) == 0 )
        {
            count++;
            if( S_ISDIR( entryInfo.st_mode ) )
            {
                ft_putstr(dir_name);
                count += open_dir(pathName);
            }
            else if( S_ISREG( entryInfo.st_mode))
            {
                printf( "\t%s has %lld bytes\n",
                    pathName, (long long)entryInfo.st_size );
            }
            else if( S_ISLNK( entryInfo.st_mode ) )
            {
                char targetName[PATH_MAX + 1];
                if( readlink( pathName, targetName, PATH_MAX ) != -1 )
                {
                    printf( "\t%s -> %s\n", pathName, targetName );
                }
                else
                {
                    printf( "\t%s -> (invalid symbolic link!)\n", pathName );
                }
            }
        } 
        else 
        {
            printf( "Error statting %s: %s\n", pathName, strerror( errno ) );
        }
        retval = readdir_r( dir, &entry, &entryPtr );
    }
    (void)closedir( dir );
    return count;
}

int         main(int argc, char **argv)
{
    char                path_name[PASS_MAX];
    
    getwd (path_name);
    int idx = 0;
    unsigned count = 0;
    open_dir(path_name);
     
    return EXIT_SUCCESS;
}