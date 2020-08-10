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

int     ft_can_add_hidden_file(const char *str, t_flags *flags)
{
    if (flags->a != 1)
    {
        if (str[0] != 1)
            return (0);
        else
            return (1);
    }
    return (1);
}

t_file    *ft_new_list(t_file *new, const char *name, const char *path, t_flags *flags)
{

}