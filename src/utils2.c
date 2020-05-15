/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 20:25:31 by cwing             #+#    #+#             */
/*   Updated: 2020/05/15 13:33:07 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char				*get_full_name(char *path_name, char *name)
{
	char			*full_name;

	full_name =  ft_strnew(PATH_MAX + NAME_MAX);
	if (full_name)
	{
		ft_strncpy(full_name, path_name, PATH_MAX + NAME_MAX);
		ft_strncat(full_name, "/", PATH_MAX + NAME_MAX);
		ft_strncat(full_name, name, PATH_MAX + NAME_MAX);
	}
	return (full_name);
}
