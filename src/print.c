/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 20:11:44 by cwing             #+#    #+#             */
/*   Updated: 2020/03/27 15:56:16 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

static void			ft_putstr_c(char *src, char *color)
{
	ft_putstr(color);
	ft_putstr(src);
	ft_putstr(STD_T);
}

static void			ft_printnum(int num)
{
	char			*buff;

	buff = NULL;
	if ((buff = ft_itoa(num)))
		ft_putstr(buff);
	ft_memdel((void**)&buff);
}

static void			print_name(t_dir *head)
{
	if (head->flags->G == 'G')
	{
		if (head->chmod[0] == 'd')
			ft_putstr_c(head->name, BLU_T);
		else if (head->chmod[0] == '-' &&
		(head->chmod[3] == 'x' || head->chmod[6] == 'x' || head->chmod[9] == 'x'))
			ft_putstr_c(head->name, GRE_T);
		else if (head->chmod[0] == 'l')
			ft_putstr_c(head->name, YWL_T);
		else
			ft_putstr_c(head->name, STD_T);
	}
	else
		ft_putstr(head->name);
}

void				simple_print(t_dir *head, char all_mod)
{
	while (head)
	{
		if(all_mod == '0' && head->name[0] == '.')
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

static void			print_line(t_dir * head)
{
	ft_putstr(head->chmod);
	ft_putchar('\t');
	ft_printnum((int)head->links);
	ft_putchar('\t');
	ft_putstr(head->u_name);
	ft_putchar('\t');
	ft_putstr(head->u_group);
	ft_putchar('\t');
	ft_printnum((int)head->size);
	ft_putchar('\t');
	ft_putstr(head->time_get);
	ft_putchar('\t');
	print_name(head);
	ft_putchar('\n');
}

void				all_print(t_dir *head, char all_mod)
{
	ft_putstr("total ");
	ft_printnum(summ_blocks(head));
	ft_putchar('\n');
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
	else
		simple_print(head, head->flags->a);
}