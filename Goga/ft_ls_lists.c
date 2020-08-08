/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacame <wacame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:53:47 by wacame            #+#    #+#             */
/*   Updated: 2020/08/08 18:45:24 by wacame           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_strcmp(const char *str1, const char *str2)
{
  	unsigned int	i;
  	unsigned char	*s1;
  	unsigned char	*s2;

  	i = 0;
  	s1 = (unsigned char *)str1;
  	s2 = (unsigned char *)str2;
  	while (s1[i] && s2[i])
	  {
		    if (s1[i] != s2[i])
	  		    return (s1[i] - s2[i]);
    		i++;
  	}
  	if ((s1[i] && !s2[i]) || (!s1[i] && s2[i]))
    		return (s1[i] - s2[i]);
  	return (0);
}


//Счетчик Файлов в директории

int    ls_files_summ(char *Name)
{
    DIR   *drct;
    int   i;

    i = 0;
    if((drct = opendir(Name)) != NULL)
    {
        while(readdir(drct) != NULL)
            i++;
        closedir(drct);
        return (i);
    }
    return (-1);
}

files         *ls_new_mass(char *Name)
{
    int             k;
    DIR             *drct;
    files           *grid;
    t_dirent        *fl;

    k = 0;
    grid = (files *)malloc(sizeof(files) * ls_files_summ(Name));
    drct = opendir(Name);
    if(drct == NULL || grid == NULL)
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

files       *ls_mass_chng(files *Grid, int Summ)
{
    files   buff;
    files   *grd;
    int     i;
    int     j;

    i = 0;
    j = 0;
    if(Grid == NULL)
        return (NULL);
    grd = Grid;
    while(i < Summ)
    {
        while(j < Summ)
        {
            if((ft_strcmp(grd[i].dir->d_name, grd[j].dir->d_name)) < 0)
            {
                buff = grd[i];
                grd[i] = grd[j];
                grd[j] = buff;
            }
            j++;
        }
        i++;
        j = 0;
    }
    j = 0;
    while(j < Summ)
        printf("%s ", grd[j++].dir->d_name);
    printf("\n");
    return (grd);
}