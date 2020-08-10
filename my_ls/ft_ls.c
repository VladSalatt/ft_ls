/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:55:57 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/09 15:55:59 by ebulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int     main(int ac, char **av)
{
    t_file      *head;
    t_flags     flags;

    flags = (t_flags){0, 0, 0, 0, 0, 0, 0, 0};
    if (ac > 1)
    {
        ft_find_flags((const char **)av, ac, &flags);          // Поиск флагов
        head = NULL;
        if (ft_only_flags((const char **)av) == 1)           // Тут только флаги?
        {
            if (flags.R == 1)                                // Проверка на флаг рекурсии
                ft_recursion_penetration("./", &flags, 0);
        }

    }
    return (0);
}