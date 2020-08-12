/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addsymb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 00:38:10 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/12 00:38:11 by ebulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// Добавление n - ого количества символов в начало строки // Готово

char 	*ft_addsymb(char *str, char c, int num)
{
	int 	i;
	int 	j;
	int 	len;
	char 	*new_str;

	i = 0;
	j = 0;
	if (num < 0)
		return (NULL);
	len = ft_strlen(str) + num;
	new_str = (char *)ft_memalloc(len);
	while (i < num)
	{
		new_str[i] = c;
		i++;
	}
	while (str[j])
	{
		new_str[i] = str[j];
		j++;
		i++;
	}
	new_str[i] = '\0';
	ft_strdel(&str);
	return (new_str);
}

char 	*ft_addsymbend(char *str, char c, int num)
{
	int		i;
	int		j;
	int 	len;
	char 	*new_str;

	i = 0;
	j = 0;
	if (num < 0)
		return (NULL);
	len = ft_strlen(str) + num;
	new_str = (char *)ft_memalloc(len);
	while (str[j])
	{
		new_str[i] = str[j];
		i++;
		j++;
	}
	while (i < len)
	{
		new_str[i] = c;
		i++;
	}
	new_str[i] = '\0';
	ft_strdel(&str);
	return (new_str);
}