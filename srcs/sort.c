/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 06:16:17 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/14 17:00:52 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_lstswap(t_file *p1, t_file *p2)
{
	t_file	tmp;

	tmp = *p1;
	ft_content_cpy(p2, p1);
	ft_content_cpy(&tmp, p2);
}

void	ft_ascii_bubble(t_file **head, int n)
{
	t_file	*h;
	t_file	*p1;
	t_file	*p2;
	int		f;

	f = 1;
	while (f)
	{
		h = *head;
		f = 0;
		while (h->next != NULL)
		{
			p1 = h;
			p2 = h->next;
			if (n == 1 ? ft_strcmp(p1->name, p2->name) > 0
				: ft_strcmp(p1->name, p2->name) < 0)
			{
				ft_lstswap(p1, p2);
				f++;
			}
			h = h->next;
		}
	}
}

void	ft_u_flag_sort(t_file **head, int n)
{
	t_file	*h;
	t_file	*p1;
	t_file	*p2;
	int		f;

	f = 1;
	while (f)
	{
		h = *head;
		f = 0;
		while (h->next != NULL)
		{
			p1 = h;
			p2 = h->next;
			if (n == 1 ? p1->last_access < p2->last_access
					: p1->last_access > p2->last_access)
			{
				ft_lstswap(p1, p2);
				f++;
			}
			h = h->next;
		}
	}
}

void	ft_t_flag_sort(t_file **head, int n)
{
	t_file	*h;
	t_file	*p1;
	t_file	*p2;
	int		f;

	f = 1;
	while (f)
	{
		h = *head;
		f = 0;
		while (h->next != NULL)
		{
			p1 = h;
			p2 = h->next;
			if (n == 1 ? p1->last_modif < p2->last_modif
					: p1->last_modif > p2->last_modif)
			{
				ft_lstswap(p1, p2);
				f++;
			}
			h = h->next;
		}
	}
}

void	ft_sort_list(t_file **head, t_flags *flags)
{
	if (*head != NULL)
	{
		flags->r == 1 ? ft_ascii_bubble(head, 0) : ft_ascii_bubble(head, 1);
		if (flags->t == 1)
		{
			if (flags->u == 1)
				flags->r == 1 ? ft_u_flag_sort(head, 0)
					: ft_u_flag_sort(head, 1);
			else
				flags->r == 1 ? ft_t_flag_sort(head, 0)
					: ft_t_flag_sort(head, 1);
		}
	}
}
