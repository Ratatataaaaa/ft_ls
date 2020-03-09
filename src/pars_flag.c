/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:47:56 by cwing             #+#    #+#             */
/*   Updated: 2020/03/09 20:19:26 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

static int          is_flag(char flag)
{
    if(flag == 'R' || flag == 'l' || flag == 'a' || flag == 'r' || flag == 't')
        return (1);
    else
        return(0);
}

char                *parsing(int argc, char **argv)
{
    
}