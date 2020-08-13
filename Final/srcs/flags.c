/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:06:32 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/09 16:06:40 by ebulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// Флаг ли это? // готово

int     ft_is_it_flag(const char *s)
{
    if (s && s[0] == '-' && s[1])
        return (1);
    else
        return (0);
}

// Валидация флага, то есть, если введены некорректные флаги, то он напечатает ОШИБКУ // готово

int     ft_valid_flag(const char *s, char *v)
{
    int     i;
    int     j;
    int     f;

    i = 1;
    if (s[1] == '-' && !s[2])
        return (2);
    while (s[i])
    {
        j = 0;
        f = 0;
        while (v[j])
        {
            if (s[i] == v[j])
                f++;
            j++;
        }
        if (f == 0)
        {
            printf("error");
            exit(1);
        }
        i++;
    }
    return (1);
}



// Кладет флаги из аргуементов в структуру флагов // Готово

int     ft_putflag(const char *av, t_flags *flags)
{
    int     i;
    int     f;

    i = 1;
    f = ft_valid_flag(av, "lRatrufg");
    if (f == 2)
        return (2);                                            // Если валидация вернет "2", то и прога дропнется с кодом "2"
    if (f)
    {
        while (av[i])
        {
            av[i] == 'l' ? flags->l = 1 : 0;
            av[i] == 'R' ? flags->R = 1 : 0;
            av[i] == 'a' ? flags->a = 1 : 0;
            av[i] == 't' ? flags->t = 1 : 0;
            av[i] == 'r' ? flags->r = 1 : 0;
            av[i] == 'u' ? flags->u = 1 : 0;
            av[i] == 'f' ? flags->f = 1 : 0;
            av[i] == 'g' ? flags->g = 1 : 0;
            i++;
        }
    }
    return (1);
}

// Ищет флаги и кладет флаги в структуру или выдает ОШИБКУ // in work

int     ft_find_flags(const char **av, int ac, t_flags *flags)
{
    int     i;
    int     f;                                                 // Переменная для ошибки
    int     m;                                                 // Переменная для ошибки

    i = 1;
    f = 0;
    while (i <= ac)
    {
        if (ft_is_it_flag(av[i]) && f == 0)
            m = ft_putflag(av[i], flags);                            //Если m == 2, то ft_putflag закончилась ошибкой
        else
            f++;
        if (ft_is_it_flag(av[i]) && f != 0)
            printf("error\n");
        if (m == 2)
            f++;
        i++;
    }
    return (1);
}
