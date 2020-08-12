/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 03:30:08 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/12 03:30:13 by ebulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 	ft_is_only_arg(t_file *head)
{
	t_file 	*tmp;
	int 	k;

	k = 0;
	tmp = head;
	while (tmp != NULL)
	{
		k++;
		tmp = tmp->next;
	}
	if (k == 1)
		return (1);
	return (0);
}

void 	ft_init(t_file *head, char **av, t_flags *flags)
{
	t_file 	*tmp;
	char 	*new_path;

	head = ft_struct_filenames(&head, (const char **)av, "", flags);
	ft_sort_list(&head, flags);
	ft_print_without_dir(&head);
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->type == T_DIR)
		{
			if (ft_is_only_arg(head) != 1)
				ft_print_path(tmp->name);
			new_path = ft_get_path(tmp->name, tmp->path);
			ft_print_dir(new_path, flags);
			ft_strdel(&new_path);
		}
		tmp = tmp->next;
	}
	/* Опять фри структуры */
}