/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_total.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:28:47 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/11 12:28:48 by ebulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// Переносим все данные из срс в дест // Готово

void    ft_content_cpy(t_file *src, t_file *dst)
{
	dst->name = src->name;
	dst->path = src->path;
	dst->type = src->type;
	dst->last_modif = src->last_modif;
	dst->last_access = src->last_access;
	dst->date = src->date;
	dst->username = src->username;
	dst->groupname = src->groupname;
	dst->size = src->size;
	dst->numlink = src->numlink;
	dst->chmod = src->chmod;
	dst->blocks = src->blocks;
}

// Подсчет тотала // готово

char 	*ft_calculate_total(t_file **head)
{
	t_file 	*tmp;
	int 	total;

	tmp = *head;
	total = 0;
	while (tmp != NULL)
	{
		total += tmp->blocks;
		tmp = tmp->next;
	}
	return (ft_itoa(total));
}
 // Печатает тотал // Готово

void 	ft_print_total(t_file **head)
{
	char 	*total;

	total = ft_calculate_total(head);
	ft_putstr("total ");
	ft_putendl(total);
	ft_strdel(&total);
}