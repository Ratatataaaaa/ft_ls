/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 20:25:31 by cwing             #+#    #+#             */
/*   Updated: 2020/05/03 22:28:19 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

char				get_file_acl(char *path)
{
	acl_t			acl;
	char			buf[101];

	acl = NULL;
	if (listxattr(path, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
		return ('@');
	if ((acl = acl_get_link_np(path, ACL_TYPE_EXTENDED)))
	{
		acl_free(acl);
		acl = NULL;
		return ('+');
	}
	return (' ');
}

char				*get_full_name(char *path_name, char *name)
{
	char			*full_name;

	full_name = NULL;
	if ((full_name = ft_strnew(PATH_MAX)))
	{
		ft_strncpy(full_name, path_name, PATH_MAX);
		ft_strncat(full_name, "/", PATH_MAX);
		ft_strncat(full_name, name, PATH_MAX);
	}
	return (full_name);
}
