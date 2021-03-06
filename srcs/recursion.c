/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:08:28 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/14 16:46:29 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file	*ft_get_rootnames(t_file **head, const char *path, t_flags *flags)
{
	t_file			*new;
	DIR				*dir;
	struct dirent	*record;

	dir = opendir(path);
	if (!dir)
	{
		ls_error((char *)path, 0);
		return (NULL);
	}
	while ((record = readdir(dir)) != NULL)
	{
		if (ft_can_add_hidden_file(record->d_name, flags) == 0)
			continue ;
		new = ft_new_list(new, record->d_name, path, flags);
		ft_push_back(&(*head), new);
	}
	closedir(dir);
	return (*head);
}

char	*ft_get_path(char *name, char *path)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strjoin(path, name);
	tmp2 = ft_strjoin(tmp1, "/");
	ft_strdel(&tmp1);
	return (tmp2);
}

void	ft_recursion_penetration(const char *path, t_flags *flags,
		int path_flag)
{
	t_file		*head;
	t_file		*tmp;
	char		*new_path;

	head = NULL;
	if (path_flag != 1)
		ft_print_path(path);
	path_flag = 0;
	head = ft_get_rootnames(&head, path, flags);
	ft_sort_list(&head, flags);
	ft_print_struct(&head, flags);
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->type == T_DIR && ft_strcmp(tmp->name, "..") != 0
				&& ft_strcmp(tmp->name, ".") != 0)
		{
			new_path = ft_get_path(tmp->name, tmp->path);
			ft_recursion_penetration((const char *)new_path, flags, 0);
			ft_strdel(&new_path);
		}
		tmp = tmp->next;
	}
	if (head != NULL)
		ls_free_list(&head);
}

void	ft_recursion_init(t_file *head, const char **av, t_flags *flags)
{
	t_file	*tmp;
	char	*new_path;
	int		path_flag;

	path_flag = 0;
	head = ft_struct_filenames(&head, (const char **)av, "", flags);
	ft_sort_list(&head, flags);
	ft_print_without_dir(&head);
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->type == T_DIR)
		{
			new_path = ft_get_path(tmp->name, tmp->path);
			path_flag = ft_is_only_arg(head);
			ft_recursion_penetration((const char *)new_path, flags, path_flag);
			ft_strdel(&new_path);
		}
		tmp = tmp->next;
	}
	if (head != NULL)
		ls_free_list(&head);
}
