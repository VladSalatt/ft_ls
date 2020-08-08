/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacame <wacame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:46:33 by wacame            #+#    #+#             */
/*   Updated: 2020/08/08 15:00:49 by wacame           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// int     main(int argc, char** argv)
// {
//     int     i;
//     int     j;
//     char    *Flag_list;
//     char    **Ways_list;

//     i = ls_flags_nbr(argv, argc);
//     Flag_list = ls_flags_list(argv, argc, i);
//     if(ls_key_valid(Flag_list))
//     {
//         j = ls_ways_nbr(argv, argc);
//         Ways_list = ls_ways_list(argv, argc, j);
//         ft_print_ways(Ways_list, j);
//         free(Flag_list);
//         //ls_free_ways(Ways_list, j);
//     }
//     return (0);
// }

int     main(int argc, char** argv)
{
    int     i;
    char    *Flag_list;
    char    **Flag_;

    i = ls_flags_nbr(argv, argc);
    Flag_list = ls_flags_list(argv, argc, i);
    printf("%s\n", Flag_list);
    if((*Flag_ = ls_flag_full(Flag_list)) != 0)
        printf("%s\n", *Flag_);
    free(Flag_list);
    return (0);
}