/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strencut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 22:02:28 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/10 22:02:29 by ebulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*second(char *str, int n)
{
    char	*segment;
    int		i;
    int		j;

    j = (int)ft_strlen(str) - (n + 1);
    i = 0;
    segment = (char *)ft_memalloc(n);
    while (i < n)
    {
        segment[i] = str[j];
        j++;
        i++;
    }
    segment[i] = '\0';
    return (segment);
}

static char		*first(char *str, int n)
{
    char	*segment;
    int		len;
    int		i;

    i = 0;
    len = (int)ft_strlen(str);
    segment = (char *)ft_memalloc(len - n);
    while (i < len - n)
    {
        segment[i] = str[i];
        i++;
    }
    segment[i] = '\0';
    return (segment);
}

char			*ft_strencut(char *str, int n, char *choice)
{
    if (str == NULL)
        return (NULL);
    if ((int)ft_strlen(str) < n || n < 0)
        return (NULL);
    if ((int)ft_strlen(str) == n)
        return (NULL);
    if (ft_strcmp(choice, "first") == 0)
        return (first(str, n));
    else if (ft_strcmp(choice, "second") == 0)
        return (second(str, n));
    return (NULL);