/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 21:47:15 by cwing             #+#    #+#             */
/*   Updated: 2020/05/07 19:22:30 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			sort_d_asci(t_dir **head)
{
	t_dir			*temp_a;
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
			if (!back)
				*head = temp_b;
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
	t_dir			*temp_a;
	t_dir			*temp_b;
	t_dir			*back;

	temp_a = *head;
	back = NULL;
	while (temp_a)
	{
		temp_b = temp_a->next;
		if (temp_b && (temp_a->timemod_d > temp_b->timemod_d))
		{
			temp_a->next = temp_b->next;
			temp_b->next = temp_a;
			if (!back)
				*head = temp_b;
			if (back)
				back->next = temp_b;
			sort_d_time(head);
		}
		back = temp_a;
		temp_a = temp_b;
	}
}

void				sort_dirs(t_dir **head)
{
	sort_d_asci(head);
	if ((*head)->flags->r == 'r')
		sort_d_rev(head);
	else if ((*head)->flags->t == 't')
	{
		sort_d_time(head);
		sort_d_rev(head);
	}
}
