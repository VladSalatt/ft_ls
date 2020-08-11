/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:08:28 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/09 17:08:29 by ebulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// Получение данных для ХЕДа // Готово

t_file      *ft_get_rootnames(t_file **head, const char *path, t_flags *flags)
{
    t_file  *new;
    DIR     *dir;
    struct dirent   *record;                // Переменная для записи

    dir = opendir(path);
    if (!dir)
    {
        perror("\ndiropen");
        return (NULL);
    }
    while ((record = readdir(dir)) != NULL)
    {
        if (ft_can_add_hidden_file(record->d_name, flags) == 0)         // Сработает, если файл скрыт
            continue ;
        new = ft_new_list(new, record->d_name, path, flags);           // Создаем новую структуру с метаданными
        ft_push_back(&(*head), new);                                  // Вставочка
    }
    closedir(dir);
    return (*head);
}

// Рекурсия // в прцоессе

void    ft_recursion_penetration(const char *path, t_flags *flags, int path_flag)
{
    t_file      *head;
    t_file      *tmp;
    char       *new_path;

    head = NULL;
    if (path_flag != 1)
        ft_print_path(path);
    path_flag = 0;
    head = ft_get_rootnames(&head, path, flags);    // Получение данных для ХЕДа
    ft_sort_list(*head, flags);

}