/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:12:47 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/09 17:12:47 by ebulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// Печатает путь // готово

void    ft_print_path(const char *path)
{
    int     i;
    int     len;

    i = 0;
    if (path[0] == '.' && path[1] == '/' && path[2] == '\0')
        return ;
    if (path[0] == '.' && path[1] == '/')
        i += 2;
    len = ft_strlen(path);
    if (path[len - 1] == '/')
        while (i != len - 1)
            ft_putchar(path[i++]);
    else
        while (path[i])
            ft_putchar(path[i++]);
    ft_putchar(':');
    ft_putchar('\n');
}

// Название говорит само за себя // ГОТОВО!!!

void 	ft_print_dir(char *path, t_flags *flags)
{
	t_file *head;

	head = NULL;
	head = ft_get_rootnames(&head, path, flags);
	ft_sort_list(&head, flags);
	ft_print_struct(&head, flags);
	ls_free_list(&head);
}

void 	ft_print_struct(t_file **head, t_flags *flags)
{
	t_file *tmp;

	tmp = *head;
	if (*head == NULL)
	{
		ft_putchar('\n');
		return ;
	}
	if (flags->l == 1)
		ft_print_flag_l(head, flags);
	else
	{
		while (tmp != NULL)
		{
			ft_putendl(tmp->name);
			tmp = tmp->next;
		}
	}
	ft_putchar('\n');
}

void 	ft_print_without_dir(t_file **head)
{
	t_file 	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		if (tmp->type != T_DIR)
			ft_putendl(tmp->name);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}