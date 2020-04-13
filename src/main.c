/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 02:22:00 by cwing             #+#    #+#             */
/*   Updated: 2020/04/13 23:41:53 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

void                recurs_run(t_dir *head);

void                run_ls(char *path, t_flags **flags)
{
    t_dir           *head;
    t_dir           *save_head;
    char            *n_path;
    
    n_path = NULL;
    head = get_dir_list(path, *flags);
    if (head)
    {
        sort_dirs(&head);
        ft_putstr(path);
        ft_putchar('\n');
        main_print(head);
        if (head->flags->R == 'R')
        {
            save_head = head;
            while (save_head != NULL)
            {
                if (save_head->chmod[0] == 'd' && ft_strcmp(save_head->name, ".") && ft_strcmp(save_head->name, ".."))
                {
                    n_path = get_full_name(path, save_head->name);
                    run_ls(n_path, flags);
                    ft_memdel((void**)&n_path);
                }
                save_head = save_head->next;
            }
        }
        free_t_dir(&head);
    }
}

int                 main(int argc, char **argv)
{
    t_flags         *flags;
    t_list          *dirs;
    t_list          *save;
    
    flags = get_flags(argc, argv);
    dirs = get_dirs(argc, argv);
    save = dirs;
    check_names(dirs);
    while (dirs)
    {
        run_ls((void*)dirs->content, &flags);
        dirs = dirs->next;
    }
    ft_free_lst(&save);
    ft_memdel((void**)&flags);
    // while (argc)
    // {
    //     /* code */
    // }

    return (0);
}