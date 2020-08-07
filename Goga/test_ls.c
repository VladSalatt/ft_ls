/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacame <wacame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:15:04 by wacame            #+#    #+#             */
/*   Updated: 2020/08/07 14:22:52 by wacame           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int     main(int argc, char** argv)
{
    DIR             *drct;
    struct dirent   *dir;

    drct = opendir(".");
    while((dir = readdir(drct)))
        printf("%s\n", dir->d_name);
    closedir(drct);
}