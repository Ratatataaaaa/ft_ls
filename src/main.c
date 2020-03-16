/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 02:22:00 by cwing             #+#    #+#             */
/*   Updated: 2020/03/16 20:26:28 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

void                print_flags(t_dir *elem)
{
    t_dir           *head;

    head = elem;
    while (head)
    {
         printf("%10s%4d%6s%6s%7lld %.12s %s\n", head->chmod, head->links,
           head->u_name, head->u_group, head->size, head->time_mod, head->name);
        head = head->next;
    }
    printf("Flags: l=%c, R=%c, a=%c, r=%c, t=%c, u=%c, f=%c, g=%c, d=%c, G=%c\n", elem->flags->l,elem->flags->R,elem->flags->a,
                                                                                    elem->flags->r,elem->flags->t,elem->flags->u,elem->flags->f,
                                                                                        elem->flags->g,elem->flags->d,elem->flags->G);
}

void                print_dirs(t_list *head)
{
    while (head)
    {
        printf("%s\n", (char*)head->content);
        head = head->next;
    }
}

int                 main(int argc, char **argv)
{
    t_dir           *head;
    t_dir           *temp;
    t_flags         *flags;
    t_list          *dirs;
    register short  i;

    i = 1;
    head = NULL;
    flags = get_flags(argc, argv);
    dirs = get_dirs(argc, argv);
    while (dirs)
    {
        head = get_dir_list((char*)dirs->content, flags);
        if (head)
        {
            print_flags(head);
            free_t_dir(&head);
        }
        dirs = dirs->next;
    }
    
    
    return (0);
}