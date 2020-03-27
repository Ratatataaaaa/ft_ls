/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 21:47:15 by cwing             #+#    #+#             */
/*   Updated: 2020/03/27 01:48:43 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

static void         sort_d_asci(t_dir **head)
{
	t_dir           *temp_a;
	t_dir			*temp_b;
	t_dir			*back;

	temp_a = *head;
	back = NULL;
	while (temp_a)
	{
		temp_b = temp_a->next;
		if (temp_b && (ft_strcmp(temp_a->name, temp_b->name) > 0))
		{
			temp_a->next = temp_b->next;
			temp_b->next = temp_a;
			if (back)
				back->next = temp_b;
			sort_d_asci(head);
		}
		back = temp_a;
		temp_a = temp_b;
	}
}

static void			sort_d_rev(t_dir **head)
{
	t_dir			*temp_a;
	t_dir			*temp_b;
	t_dir			*temp_c;

	temp_a = NULL;
	temp_b = *head;
	while (temp_b)
	{
		temp_c = temp_b->next;
		temp_b->next = temp_a;
		temp_a = temp_b;
		temp_b = temp_c;
	}
	*head = temp_a;
}

static void			sort_d_time(t_dir **head)
{
	t_dir           *temp_a;
	t_dir			*temp_b;
	t_dir			*back;

	temp_a = *head;
	back = NULL;
	while (temp_a)
	{
		temp_b = temp_a->next;
		if (temp_b && (temp_a->time_get > temp_b->time_get))
		{
			temp_a->next = temp_b->next;
			temp_b->next = temp_a;
			if (back)
				back->next = temp_b;
			sort_d_time(head);
		}
		back = temp_a;
		temp_a = temp_b;
	}
}

void                sort_dirs(t_dir **head)
{
	if ((*head)->flags->f == '0')
	{
		sort_d_asci(head);
		if ((*head)->flags->R == 'R')
		{
			free_t_dir(head, 'A');
			free_t_dir(head, 'A');
		}
		if ((*head)->flags->r == 'r')
			sort_d_rev(head);
		else if ((*head)->flags->t == 't' || (*head)->flags->u == 'u')
			sort_d_time(head);
	}
}