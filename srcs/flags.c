/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 17:24:15 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/14 17:24:20 by ebulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_is_it_flag(const char *s)
{
	if (s && s[0] == '-' && s[1])
		return (1);
	else
		return (0);
}

int		ft_valid_flag(const char *s, char *v)
{
	int		i;
	int		j;
	int		f;

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
			s = s + i;
			ls_error((char *)s, USAGE);
		}
		i++;
	}
	return (1);
}

int		ft_putflag(const char *av, t_flags *flags)
{
	int		i;
	int		f;

	i = 1;
	f = ft_valid_flag(av, "lRatrufg");
	if (f == 2)
		return (2);
	if (f)
	{
		while (av[i])
		{
			av[i] == 'l' ? flags->l = 1 : 0;
			av[i] == 'R' ? flags->br = 1 : 0;
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

void	ft_dis_flags(t_flags *flags)
{
	flags->a = 1;
	flags->r = 0;
	flags->t = 0;
}

int		ft_find_flags(const char **av, int ac, t_flags *flags)
{
	int		i;
	int		f;
	int		m;

	i = 1;
	f = 0;
	while (i <= ac)
	{
		if (ft_is_it_flag(av[i]) && f == 0)
			m = ft_putflag(av[i], flags);
		else
			f++;
		if (ft_is_it_flag(av[i]) && f != 0)
			ft_print_error(av[i]);
		if (m == 2)
			f++;
		i++;
	}
	if (flags->f == 1)
		ft_dis_flags(flags);
	return (1);
}
