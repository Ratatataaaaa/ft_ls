/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:20:41 by cwing             #+#    #+#             */
/*   Updated: 2020/03/30 01:31:07 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

void                ft_lst_push_back_(t_list **head, t_list *new_elem)
{
	t_list			*find;

	find = *head;
	if (find)
    {
        while (find->next)
            find = find->next;
        find->next = new_elem;
    }
    else
        *head = new_elem;
}

void                ft_free_lst(t_list **head)
{
    t_list          *to_del;

    if (head && *head)
    {
        while ((*head))
        {
            to_del = *head;
            *head = (*head)->next;
            ft_memdel((void**)&(to_del->content));
            ft_memdel((void**)&to_del);
        }
    }
    head = NULL;
}

int                 dirs_count(t_list *head, t_dir *start)
{
    int             i;

    i = 0;
    while (head)
    {
        i++;
        head = head->next;
    }
    while (start)
    {
        start->count_dirs = i;
        start = start->next;
    }
    
    return (i);
}

static void         have_dirs(t_list **head)
{
    char            *dir;

    dir = ft_strnew(3);
    if (dir && !(*head))
    {
        ft_strcpy(dir, ".");
        *head = ft_lstnew(dir, 3);
    }
    ft_memdel((void**)&dir);
    return;
}

t_list              *get_dirs(int argc, char **argv)
{
    t_list          *head;
    t_list          *temp;
    int             i;

    i = 1;
    head = NULL;
    while (i < argc)
    {
        if (argv[i][0] == '-')
        {
            i++;
            continue;
        }
        else
        {
            if ((temp = ft_lstnew(argv[i], ft_strlen(argv[i]))))
                ft_lst_push_back_(&head, temp);
            else
            {
                ft_free_lst(&head);
                return (head);
            }
        }
        i++;
    }
    have_dirs(&head);
    return(head);
}