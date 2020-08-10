/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacame <wacame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:13:58 by wacame            #+#    #+#             */
/*   Updated: 2020/08/10 15:33:18 by wacame           ###   ########.fr       */
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
#include <string.h>
#include <errno.h> 


typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct ft_ls
{
    t_stat     *stt;
    t_dirent   *dir;
} files;

enum	{ERRNO, USAGE, MALL_ERR};

char    *strerror(int __errnum);
int     ft_strlen(char *str);
int     ft_print_ways(char **Ways, int Summ);
int     ls_ways_nbr(char **Ways, int Nbr);
char    **ls_ways_list(char **ways, int Nbr, int Summ);
int     ls_flags_nbr(char **Flags, int Nbr);
char    *ls_flags_list(char **Flags, int Nbr, int Summ);
int     ls_flag_valid(char* Flags);
char    *ls_flag_full(char *Flags);
files   *ls_new_mass(char *Name);
files   *ls_mass_chng(files *Grid, int Summ, char *name);
int     ls_files_summ(char *Name);
int		ls_error(char *s, int error);

#endif