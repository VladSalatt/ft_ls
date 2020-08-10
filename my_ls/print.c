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
    if (path[0] == '.' && path[1] == '/' && path[2])
        return;
    if (path[0] == '.' && path[1] == '/')
        i += 2;
    len = ft_strlen(path);
    if (path[len--] == '/')
        while (i != len--)
            ft_putchar(path[i++]);
    else
        while (path[i])
            ft_putchar(path[i++]);
    ft_putchar(':');
    ft_putchar('\n');
}
