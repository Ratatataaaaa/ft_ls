/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 20:11:44 by cwing             #+#    #+#             */
/*   Updated: 2020/05/09 13:31:54 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				simple_print(t_dir *head, char all_mod)
{
	while (head)
	{
		if (all_mod == '0' && head->name[0] == '.')
		{
			head = head->next;
			continue;
		}
		print_name(head);
		ft_putchar('\t');
		head = head->next;
	}
	ft_putchar('\n');
}

static void			print_line(t_dir *head)
{
	ft_putstr(head->chmod);
	ft_putchar(' ');
	ft_printnum((int)head->links);
	ft_putchar('\t');
	ft_putstr(head->u_name);
	ft_putchar('\t');
	ft_putstr(head->u_group);
	ft_putchar('\t');
	ft_printnum((int)head->size);
	ft_putchar('\t');
	ft_putstr(head->time_mod);
	ft_putchar('\t');
	print_name(head);
	if (head->chmod[0] == 'l')
	{
		ft_putstr(" -> ");
		ft_putstr(head->linkpath);
	}
	ft_putchar('\n');
}

void				all_print(t_dir *head, char all_mod)
{
	if (head->next != NULL)
	{
		ft_putstr("total ");
		ft_printnum(summ_blocks(head));
		ft_putchar('\n');
	}
	while (head)
	{
		if (all_mod == '0' && head->name[0] == '.')
		{
			head = head->next;
			continue;
		}
		print_line(head);
		head = head->next;
	}
}

void				main_print(t_dir *head)
{
	if (head->flags->l == 'l')
		all_print(head, head->flags->a);
	else if (head->flags->one == '1')
		print_one(head, head->flags->a);
	else
		simple_print(head, head->flags->a);
}

void				print_one(t_dir *head, char all_mod)
{
	while (head)
	{
		if (all_mod == '0' && head->name[0] == '.')
		{
			head = head->next;
			continue;
		}
		print_name(head);
		ft_putchar('\n');
		head = head->next;
	}
}
