/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 02:22:00 by cwing             #+#    #+#             */
/*   Updated: 2020/03/09 19:46:26 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

int                 main(int argc, char **argv)
{
    t_dir           *head;
    t_dir           *temp;
    register short  i;

    i = 1;
    head = NULL;
    if (argc == 1)
    {
        head = get_dir_list(".");
        temp = head;
        while (head)
        {
            printf("%10s%4d%6s%6s%7lld %.12s %s\n", head->chmod, head->links,
            head->u_name, head->u_group, head->size, head->time_, head->name);
            head = head->next;
        }
        free_t_dir(&temp);
    }
    else
    {
        while (i < argc)
        {
            head = get_dir_list(argv[i]);
            temp = head;
            while (head)
            {
                printf("%10s%4d%6s%6s%7lld %.12s %s\n", head->chmod, head->links,
                head->u_name, head->u_group, head->size, head->time_, head->name);
                head = head->next;
            }
            free_t_dir(&temp);
            ft_putstr(argv[i]);
            ft_putstr(":\n");
            i++;
        }
    }   
    while (argv)
    {
        
    }
    
    return (0);
}