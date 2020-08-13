/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:07:09 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/13 22:07:11 by ebulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file 	*ls_free_list(t_file **List_to_free)
{
	t_file	*list_copy;
	t_file	*scd_list_copy;

	if (!List_to_free)
		return (NULL);
	list_copy = *List_to_free;
	while (list_copy)
	{
		scd_list_copy = list_copy->next;
		free(list_copy->name);
		free(list_copy->path);
		list_copy->type = -1;
		free(list_copy->date);
		free(list_copy->username);
		free(list_copy->groupname);
		free(list_copy->chmod);
		free(list_copy->size);
		free(list_copy->numlink);
		list_copy->blocks = -1;
		list_copy->last_modif = -1;
		list_copy->last_access = -1;
		free(list_copy);
		list_copy = scd_list_copy;
	}
	return list_copy;
}
