/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:47:55 by cwing             #+#    #+#             */
/*   Updated: 2020/03/04 16:04:46 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

char                *get_time(time_t *time_)
{
	time_t	today;
	char	*str_time;

    str_time = NULL;
	time(&today);
	str_time = ctime(time_) + 4;
    return (str_time);
}
