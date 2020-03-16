/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 01:53:27 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/03/16 18:52:42 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lst_push_back(t_list **alst,
		void const *content, size_t content_size)
{
	t_list			*temp;
	t_list			*find;

	find = *alst;
	if (alst && (temp = ft_lstnew(content, content_size)))
	{
		while (find->next)
			find = find->next;
		find = temp;
	}
	else
		*alst = temp;
}
