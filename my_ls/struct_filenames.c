/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_filenames.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:35:42 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/10 14:35:43 by ebulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// Скрытые файлы (".") // Готово

int     ft_can_add_hidden_file(const char *str, t_flags *flags)
{
    if (flags->a != 1)
    {
        if (str[0] == '.')
            return (0);
        else
            return (1);
    }
    return (1);
}

// Заполнение новой структуры // Готово

t_file    *ft_new_list(t_file *new, const char *name, const char *path, t_flags *flags)
{
    char *full_name;

    if (!(new = malloc(sizeof(t_file))))
        exit(1);
    full_name = ft_strjoin(path, name);
    if (ft_whats_specific((const char *)full_name, &new, flags) == 0)       // Проверка на обишку
    {
        ft_strdel(&full_name);
        return (NULL);
    }
    new->name = ft_strdup(name);
    new->path = ft_strdup(path);
    new->next = NULL;
    ft_strdel(&full_name);
    return (new);
}