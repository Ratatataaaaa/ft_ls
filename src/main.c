/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 02:22:00 by cwing             #+#    #+#             */
/*   Updated: 2020/05/07 17:14:53 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

static void			recurs_run(t_dir *head, t_flags **flags, char *path, int a)
{
	t_dir			*save_head;
	char			*n_path;

	save_head = head;
	n_path = NULL;
	while (save_head != NULL)
	{
		if (save_head->chmod[0] == 'd' && ft_strcmp(save_head->name, ".") &&
			ft_strcmp(save_head->name, ".."))
		{
			n_path = get_full_name(path, save_head->name);
			run_ls(n_path, flags, a);
			ft_memdel((void**)&n_path);
		}
		save_head = save_head->next;
	}
}

void				run_ls(char *path, t_flags **flags, int argc)
{
	t_dir			*head;

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
			recurs_run(head, flags, path, argc);
		}
		free_t_dir(&head);
	}
}

int					main(int argc, char **argv)
{
	t_flags			*flags;
	t_list			*dirs;
	t_list			*save;

	flags = get_flags(argc, argv);
	if (!flags)
		return(EXIT_SUCCESS);
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
	return (EXIT_SUCCESS);
}
