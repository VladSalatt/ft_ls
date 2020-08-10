/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacame <wacame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:46:33 by wacame            #+#    #+#             */
/*   Updated: 2020/08/10 20:09:16 by wacame           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"



int     main(int argc, char** argv)
{
    int     i;
    int     j;
    char    *Flag_list;
    char    **Ways_list;
    files   *Grid;

    i = ls_flags_nbr(argv, argc);
    Flag_list = ls_flags_list(argv, argc, i);
    if(ls_flag_valid(Flag_list) && i != -1)
    {
        i = 0;
        Flag_list = ls_flag_full(Flag_list);
        j = ls_ways_nbr(argv, argc);
        Ways_list = ls_ways_list(argv, argc, j);
        while(i < j)
        {
            Grid = ls_mass_chng(ls_new_mass(Ways_list[i]),
                ls_files_summ(Ways_list[i]), Ways_list[i]);
            i++;
        }
        if(j == 0 && argc == 1)
            Grid = ls_mass_chng(ls_new_mass("./"), ls_files_summ("./")
                , "./");

        //ft_print_ways(Ways_list, j);
        free(Flag_list);
        if (!Grid)
            free(Grid);
        //ls_free_ways(Ways_list, j);
    }
    return (0);
}

// int     main(void)
// {
//     int     i;
//     files   *Grid;

//     i = ls_files_summ("./rrr/");
//     if(i != -1)
//     {
//         Grid = ls_mass_chng(ls_new_mass("./rrr"), i, "./rrr");
//         free(Grid);
//     }
//     return (0);
// }