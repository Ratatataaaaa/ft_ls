/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 02:22:00 by cwing             #+#    #+#             */
/*   Updated: 2020/03/10 18:41:54 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

void                print_flags(t_dir *elem)
{
    printf("Flags: l=%c, R=%c, a=%c, r=%c, t=%c, u=%c, f=%c, g=%c, d=%c, G=%c\n", elem->flags->l,elem->flags->R,elem->flags->a,
                                                                                    elem->flags->r,elem->flags->t,elem->flags->u,elem->flags->f,
                                                                                        elem->flags->g,elem->flags->d,elem->flags->G);
}

int                 main(int argc, char **argv)
{
    t_dir           *head;
    t_dir           *temp;
    t_flags         *flags;
    register short  i;

    i = 1;
    head = NULL;
    flags = get_flags(argc, argv);
    if (argc == 1)
    {
        head = get_dir_list(".", flags);
        temp = head;
        while (head)
        {
            printf("%10s%4d%6s%6s%7lld %.12s %s\n", head->chmod, head->links,
            head->u_name, head->u_group, head->size, head->time_mod, head->name);
            print_flags(head);
            head = head->next;
        }
        free_t_dir(&temp);
    }
    else
    {
        while (i < argc)
        {
            head = get_dir_list(argv[i], flags);
            temp = head;
            while (head)
            {
                printf("%10s%4d%6s%6s%7lld %.12s %s\n", head->chmod, head->links,
                head->u_name, head->u_group, head->size, head->time_mod, head->name);
                print_flags(head);
                head = head->next;
            }
            free_t_dir(&temp);
            ft_putstr(argv[i]);
            ft_putstr(":\n");
            i++;
        }
    }
    
    return (0);
}