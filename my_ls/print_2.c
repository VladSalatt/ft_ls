/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:50:56 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/10 18:50:58 by ebulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_whats_tools(t_file **new, mode_t mode, uid_t uid, gid_t gid)
{
    struct passwd   *pwd;
    struct group    *group;

    if (S_ISREG(mode))
        (*new)->type = T_FILE;
    else if (S_ISDIR(mode))
        (*new)->type = T_DIR;
    else if (S_ISLNK(mode))
        (*new)->type = T_LINK;
    pwd = getpwuid(uid);
    (*new)->username = ft_strdup(pwd->pw_name);
    group = getgrgid(gid);
    (*new)->groupname = ft_strdup(group->gr_name);
}
