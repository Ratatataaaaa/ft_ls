/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OT_DEF.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 20:22:41 by cwing             #+#    #+#             */
/*   Updated: 2020/04/27 17:58:30 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OT_DEF_H
# define OT_DEF_H
# define RED_T		"\x1b[31m"
# define GRE_T		"\x1b[32m"
# define BLU_T		"\x1b[36m"
# define YWL_T		"\x1b[33m"
# define STD_T		"\x1b[0m"

# ifndef __APPLE__
# define st_atimespec st_atime
# define st_ctimespec st_ctime 
# define st_mtimespec st_mtime
# endif

#endif