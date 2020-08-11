/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacame <wacame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:53:47 by wacame            #+#    #+#             */
/*   Updated: 2020/08/10 20:40:12 by wacame           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ls_strcmp(const char *str1, const char *str2)
{
    unsigned int	i;
    unsigned int    j;
    unsigned char	*s1;
    unsigned char	*s2;

    i = 0;
    j = 0;
    s1 = (unsigned char *)str1;
    s2 = (unsigned char *)str2;
    while(s1[i] && s2[j])
    {
        if(ft_isalnum(s1[i]) == 0 && s1[i] != '\0')
            i++;
        if(ft_isalnum(s2[j]) == 0 && s2[j] != '\0')
            j++; 
        if (ft_tolower(s1[i]) != ft_tolower(s2[j]) )
                return (ft_tolower(s1[i]) - ft_tolower(s2[j]));
        i++;
        j++;
    }
    if ((s1[i] && !s2[j]) || (!s1[i] && s2[j]))
        return (ft_tolower(s1[i]) - ft_tolower(s2[j]));
    if (i > j)
        return (-1);
    else
        return (1);
    return (0);
}


//Счетчик Файлов в директории

int    ls_files_summ(char *Name)
{
    DIR   *drct;
    int   i;

    i = 0;
    if(!(drct = opendir(Name)))
        return (-1);
    while(readdir(drct) != NULL)
        i++;
    closedir(drct);
    return (i);
}

// Создание массива структуры, в которой хранится инф-я 
// о файле.

files         *ls_new_mass(char *Name)
{
    int             flg;
    int             k;
    DIR             *drct;
    files           *grid;
    t_dirent        *fl;

    k = 0;
    flg = ls_files_summ(Name);
    grid = (files *)malloc(sizeof(files) * flg);
    if(grid == NULL || flg == -1 || !(drct = opendir(Name)))
        return(NULL);
    while((fl = readdir(drct)) != NULL)
    {
        grid[k].dir = fl;
        stat(grid[k].dir->d_name, grid[k].stt);
        k++;
    }
    closedir(drct);
    return (grid);
}

// Сортировка массива файлов в папке по имени
// пока что работает не так как нормальная сортировка
// в ls

files   *ls_mass_chng(files *Grid, int Summ, char *Name)
{
    files   buff;
    files   *grd;
    int     i;
    int     j;
    DIR     *dr;

    i = 0;
    j = 0;
    if(Grid == NULL || Summ == -1 || Name == NULL
        || !(dr = opendir(Name)))
        return (NULL);
    grd = Grid;
    while(i < Summ)
    {
        while(j < Summ)
        {
            if((ls_strcmp(grd[i].dir->d_name, grd[j].dir->d_name)) < 0)
            {
                buff = grd[i];
                grd[i] = grd[j];
                grd[j] = buff;
            }
            j++;
        }
        j = 0;
        i++;
    }
    j = 0;
    while(j < Summ)
        printf("%s ", grd[j++].dir->d_name);
    printf("\n");
    closedir(dr);
    return (grd);
}
