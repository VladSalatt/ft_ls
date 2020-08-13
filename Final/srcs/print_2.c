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

#include "../includes/ft_ls.h"

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

// Печатает часть инфы при выхове флага -l // Готово

void 	ft_print_flag_l_tools(t_file *tmp, t_flags *flags)
{
	ft_putstr(tmp->chmod);
	ft_putstr("  ");
	ft_putstr(tmp->numlink);
	ft_putstr(" ");
	flags->g == 1 ? 0 : ft_putstr(tmp->username);
	flags->g == 1 ? 0 : ft_putstr("  ");
	ft_putstr(tmp->groupname);
	ft_putstr("  ");
	ft_putstr(tmp->size);
	ft_putstr(" ");
	ft_putstr(tmp->date);
	ft_putstr(" ");
	ft_putstr(tmp->name);
}

// Печатает всю инфу при вызове флага -l // Готово

void 	ft_print_flag_l(t_file **head, t_flags *flags)
{
	t_file 	*tmp;
	char 	buf[NAME_MAX + 1];
	char 	*tmpstr;

	tmp = *head;
	*head = ft_restruct(head);
	ft_print_total(head);
	while (tmp != NULL)
	{
		ft_print_flag_l_tools(tmp, flags);
		if (tmp->type == T_LINK)
		{
			ft_bzero(buf, NAME_MAX + 1);
			tmpstr = ft_strjoin(tmp->path, tmp->name);
			readlink(tmpstr, buf, NAME_MAX);
			ft_strdel(&tmpstr);
			ft_putstr(" -> ");
			ft_putendl(buf);
		}
		else
			ft_putchar('\n');
		tmp = tmp->next;
	}
}