/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 02:22:00 by cwing             #+#    #+#             */
/*   Updated: 2020/04/28 14:53:16 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

void                print_dirs_in_t_dir(t_dir *head)
{
    while (head)
    {
        ft_putstr(head->name);
        if (head->name[0] == '\0')
            ft_putstr("FUCK!");
        ft_putstr(" = ");
        head = head->next;
    }
    ft_putchar('\n');
    sleep(2);
}

void                run_ls(char *path, t_flags **flags, int argc)
{
    t_dir           *head;
    t_dir           *save_head;
    char            *n_path;
    
    n_path = NULL;
    save_head = NULL;
    head = NULL;
    head = get_dir_list(path, flags);
    if (head)
    {
        sort_dirs(&head);
		if (argc > 2 && flags)
		{
			ft_putstr(path);
			if (path[ft_strlen(path) - 1] != '/')
				ft_putstr("/:\n");
			else
				ft_putstr(":\n");
		}
        main_print(head);
        if (head->flags->R == 'R')
        {
            save_head = head;
            while (save_head != NULL)
            {
                if (save_head->chmod[0] == 'd' && ft_strcmp(save_head->name, ".") &&
                    ft_strcmp(save_head->name, ".."))
                {
                    if (save_head->name[0] == '\0')
                        sleep(2);
                    n_path = get_full_name(path, save_head->name);
                    run_ls(n_path, flags, argc);
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
    check_names(dirs, &flags);
    while (dirs)
    {
        run_ls((void*)dirs->content, &flags, argc);
        dirs = dirs->next;
    }
    ft_free_lst(&save);
    ft_memdel((void**)&flags);
    // while (argc)
    // {
    //     /* code */
    // }

}