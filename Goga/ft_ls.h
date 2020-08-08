/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacame <wacame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:13:58 by wacame            #+#    #+#             */
/*   Updated: 2020/08/08 14:57:32 by wacame           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
#define FT_LS

#include <time.h>
//#include <grd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
//#include <attr/xattr.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

typedef struct ft_ls
{
    struct stat     stt;
    struct dirent   dir;
    //struct ft_ls    next;
} files;

enum	{ERRNO, USAGE, MALL_ERR};

int     ft_strlen(char *str);
int     ft_print_ways(char **Ways, int Summ);
int     ls_ways_nbr(char **Ways, int Nbr);
char    **ls_ways_list(char **ways, int Nbr, int Summ);
int     ls_flags_nbr(char **Flags, int Nbr);
char    *ls_flags_list(char **Flags, int Nbr, int Summ);
int     ls_flag_valid(char* Flags);
char    *ls_flag_full(char *Flags);

#endif