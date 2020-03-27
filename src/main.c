/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 02:22:00 by cwing             #+#    #+#             */
/*   Updated: 2020/03/27 16:25:36 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

void                run_ls(char *dirs, t_flags **flags, int dir_count)
{
    t_dir           *head;
    t_dir           *save_head;

    head = get_dir_list(dirs, *flags);
    if (head)
    {
        sort_dirs(&head);
        if (head->flags->R == 'R')
        {
            save_head = head;
            while (save_head)
            {
                if (save_head->chmod[0] == 'd')
                    run_ls(save_head->name, flags, 1);
                save_head = save_head->next;
            }
        }
        if (dir_count > 1)
        {
            ft_putstr(dirs);
            ft_putstr(" :\n");
        }
        main_print(head);
        free_t_dir(&head, 'B');
    }
}

int                 main(int argc, char **argv)
{
    t_flags         *flags;
    t_list          *dirs;
    t_list          *temp;
    int             dir_count;
    
    flags = get_flags(argc, argv);
    dirs = get_dirs(argc, argv);
    check_names(dirs);
    temp = dirs;
    dir_count = dirs_count(dirs);
    while (dirs)
    {
        run_ls((char*)(dirs->content), &flags, dir_count);
        dirs = dirs->next;
    }
    ft_free_lst(&temp);
    ft_memdel((void**)&flags);
    
    return (0);
}