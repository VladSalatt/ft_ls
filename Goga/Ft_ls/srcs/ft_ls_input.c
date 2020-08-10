/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacame <wacame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 13:31:26 by wacame            #+#    #+#             */
/*   Updated: 2020/08/10 20:38:58 by wacame           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ls_free_ways(char **Ways, int Nbr)
{
    int     i;
    char    **list;

    i = 0;
    list = Ways;
    while(i != Nbr)
    {
        printf("\n%d FREE!!! - %s\n", Nbr, *list);
        free(*list);
        i++;
        if(i != Nbr)
            list++;
    }
    free(list);
    //printf("FREE!!! - %s\n", *Ways);
}

int     ft_print_ways(char **Ways, int Summ)
{
    int     i;
    char    **list;

    list = Ways;
    i = 0;
    while(i < Summ)
    {
        printf("%s\n", *list);
        list++;
        i++;
    }
    return (0);
}

int     ls_ways_nbr(char **Ways, int Nbr)
{
    int     i;
    int     Summ;
    DIR     *dr;

    Summ = 0;
    i = 0;
    while (i++ != (Nbr - 1))
    {
        if (Ways[i][0] != '-' && (dr = opendir(Ways[i])))
        {
            Summ++;
            closedir(dr);
        }
        else if (!(dr = opendir(Ways[i])))
        {
            ls_error(Ways[i], 0);
            Ways[i][0] = '-';
        }
    }
    return (Summ);
}

char    **ls_ways_list(char **Ways, int Nbr, int Summ)
{
    int     i;
    char    **List;
    char    **True_List;
    char    **True_Ways;

    i = 0;
    True_Ways = Ways;
    True_Ways++;
    List = (char **)malloc(sizeof(char *) * (Summ));
    True_List = List;
    while (i++ != (Nbr - 1))
    {
        if (*True_Ways[0] != '-')
        {
            *True_List = (char *)malloc(sizeof(char)
                * (ft_strlen(*True_Ways)));
            *True_List = *True_Ways;
            True_List++;
        }
        True_Ways++;
    }
    //ft_print_ways(List, Summ);
    return (List);
}

int     ls_flags_nbr(char **Flags, int Nbr)
{
    int     i;
    int     j;
    int     Summ;

    Summ = 0;
    i = 0;
    j = 0;
    while (i++ != (Nbr - 1))
    {
        if (Flags[i][0] == '-')
            while (Flags[i][++j] != '\0')
                Summ++;
        j = 0;
    }
    return (Summ);
}

char    *ls_flags_list(char **Flags, int Nbr, int Summ)
{
    int     i;
    int     j;
    int     k;
    char    *List;

    i = 0;
    j = 0;
    k = 0;
    List = (char *)malloc(sizeof(char) * (Summ + 1));
    List[Summ] = '\0';
    while (i++ != (Nbr - 1))
    {
        if (Flags[i][0] == '-')
            while (Flags[i][++j] != '\0')
                List[k++] = Flags[i][j];
        j = 0;
    }
    return (List);
}