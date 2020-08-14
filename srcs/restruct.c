/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 00:32:02 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/14 16:54:35 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file	*ft_restruct_size(t_file **head)
{
	t_file	*tmp;
	int		maxlen;
	int		len;

	tmp = *head;
	maxlen = 0;
	while (tmp != NULL)
	{
		if ((len = (int)ft_strlen(tmp->size)) > maxlen)
			maxlen = len;
		tmp = tmp->next;
	}
	tmp = *head;
	while (*head != NULL)
	{
		if ((len = ft_strlen((*head)->size)) < maxlen)
			(*head)->size = ft_addsymb((*head)->size, ' ', maxlen - len);
		(*head) = (*head)->next;
	}
	*head = tmp;
	return (*head);
}

t_file	*ft_restruct_groupname(t_file **head)
{
	t_file	*tmp;
	int		maxlen;
	int		len;

	tmp = *head;
	maxlen = 0;
	while (tmp != NULL)
	{
		if ((len = ft_strlen(tmp->groupname)) > maxlen)
			maxlen = len;
		tmp = tmp->next;
	}
	tmp = *head;
	while (*head != NULL)
	{
		if ((len = ft_strlen((*head)->groupname)) < maxlen)
			(*head)->groupname = ft_addsymbend((*head)->groupname,
					' ', maxlen - len);
		(*head) = (*head)->next;
	}
	*head = tmp;
	return (*head);
}

t_file	*ft_restruct_username(t_file **head)
{
	t_file	*tmp;
	int		maxlen;
	int		len;

	tmp = *head;
	maxlen = 0;
	while (tmp != NULL)
	{
		if ((len = ft_strlen(tmp->username)) > maxlen)
			maxlen = len;
		tmp = tmp->next;
	}
	tmp = *head;
	while (*head != NULL)
	{
		if ((len = ft_strlen((*head)->username)) < maxlen)
			(*head)->username = ft_addsymbend((*head)->username,
					' ', maxlen - len);
		(*head) = (*head)->next;
	}
	*head = tmp;
	return (*head);
}

t_file	*ft_restruct_numlink(t_file **head)
{
	t_file	*tmp;
	int		maxlen;
	int		len;

	tmp = *head;
	maxlen = 0;
	while (tmp != NULL)
	{
		if ((len = (int)ft_strlen(tmp->numlink)) > maxlen)
			maxlen = len;
		tmp = tmp->next;
	}
	tmp = *head;
	while (*head != NULL)
	{
		if ((len = ft_strlen((*head)->numlink)) < maxlen)
			(*head)->numlink = ft_addsymb((*head)->numlink, ' ', maxlen - len);
		(*head) = (*head)->next;
	}
	*head = tmp;
	return (*head);
}

t_file	*ft_restruct(t_file **head)
{
	*head = ft_restruct_numlink(head);
	*head = ft_restruct_username(head);
	*head = ft_restruct_groupname(head);
	*head = ft_restruct_size(head);
	return (*head);
}
