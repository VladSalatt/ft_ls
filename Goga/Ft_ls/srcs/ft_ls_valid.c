/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacame <wacame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:15:04 by wacame            #+#    #+#             */
/*   Updated: 2020/08/10 20:39:25 by wacame           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//длина масссива без символа "0"

static int 	ls_strlen(char	*Str)
{
	int		i;
	int		k;

	i = -1;
	k = 0;
	if(Str == NULL)
		return (-1);
	while(Str[++i] != '\0')
		if(Str[i] != '0')
			k++;
	return (k);
}

//Валидация ключей

int		ls_flag_valid(char* Flags)
{
	char	*newFlags;

	newFlags = Flags;
    while(*newFlags != '\0')
    {
        if (ft_strchr("lRratufgGd", *newFlags) == NULL)
		{
			ls_error(newFlags, USAGE);
            return (0);
		}
		newFlags++;
    }
    return (1);
}

//Удаление повторяющихся символов

static char	*ls_flag_del_dbl(char* Flags)
{
    int     i;
    int     j;

	i = -1;
	while(Flags[++i] != '\0')
	{
		j = i + 1;
		while(Flags[j] != '\0' && Flags[i] != '0')
		{
			if(Flags[i] == Flags[j])
				Flags[j] = '0';
			j++;
		}
	}
	return (Flags);
}

//переопределение массива ключей

static char	*ls_new_flag_mass(char *Flags)
{
	int		i;
	int		j;
	char	*newFlags;

	i = -1;
	j = 0;
	if(Flags == NULL)
		return(NULL);
	Flags = ls_flag_del_dbl(Flags);
	newFlags = (char *)malloc(sizeof(char) * (ls_strlen(Flags) + 1));
	if(newFlags == NULL)
		return (NULL);
	newFlags[ls_strlen(Flags)] = '\0';
	while (Flags[++i] != '\0' && j != ls_strlen(Flags))
		if(Flags[i] != '0')
		{
			newFlags[j] = Flags[i];
			j++;
		}
	return (newFlags);
}

char	*ls_flag_full(char *Flags)
{
	if(!(Flags))
		return (0);
	if(ls_flag_valid(Flags) == 0)
		return (0);
	Flags = ls_new_flag_mass(Flags);
	//printf("%s\n", Flags);
	return (Flags);
}