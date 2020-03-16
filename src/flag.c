/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:47:56 by cwing             #+#    #+#             */
/*   Updated: 2020/03/16 18:21:55 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FT_LS.h"

int                 is_flag(char flag)
{
    if(flag == 'l' || flag =='R' || flag == 'a' || flag == 'r' || flag == 't' ||
        flag == 'u' || flag == 'f' || flag == 'g' ||flag == 'd' || flag == 'G')
        return(1);
    else
        return(0);
}

void                null_flags(t_flags  *flags)
{
    flags->a = '0';
    flags->d = '0';
    flags->f = '0';
    flags->G = '0';
    flags->g = '0';
    flags->l = '0';
    flags->R = '0';
    flags->r = '0';
    flags->t = '0';
    flags->u = '0';
}

void                add_flag(char *arg, t_flags *flags)
{
    int             i;

    i = 0;
    while (arg[++i])
    {
        flags->l = (arg[i] == 'l') ? 'l' : flags->l;
        flags->R = (arg[i] == 'R') ? 'R' : flags->R;
        flags->a = (arg[i] == 'a') ? 'a' : flags->a;
        flags->r = (arg[i] == 'r') ? 'r' : flags->r;
        flags->t = (arg[i] == 't') ? 't' : flags->t;
        flags->u = (arg[i] == 'u') ? 'u' : flags->u;
        flags->f = (arg[i] == 'f') ? 'f' : flags->f;
        flags->g = (arg[i] == 'g') ? 'g' : flags->g;
        flags->d = (arg[i] == 'd') ? 'd' : flags->d;
        flags->G = (arg[i] == 'G') ? 'G' : flags->G;
    }
}

t_flags             *get_flags(int argc, char **argv)
{
    t_flags         *flags;
    int             i;

    i = 0;
    if((flags = malloc(sizeof(t_flags))))
    {
        null_flags(flags);
        while(++i < argc)
        {
            if ((argv[i][0] == '-') && is_flag(argv[i][1]))
                add_flag(argv[i], flags);
            else
            {
                continue;
            }
        }
    }
    return (flags);
}