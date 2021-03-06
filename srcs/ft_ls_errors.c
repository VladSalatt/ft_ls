/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacame <wacame@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 13:41:53 by wacame            #+#    #+#             */
/*   Updated: 2020/08/10 20:39:10 by wacame           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_puterror(const char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

void	ft_print_error(const char *av)
{
	ft_puterror("ft_ls: ");
	ft_puterror(av);
	ft_puterror(": No such file or directory");
	write(1, "\n", 1);
}

int		ls_error(char *s, int error)
{
	if (error == USAGE)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(*s, 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage: ft_ls [-lRatrufg] [file ...]", 2);
	}
	else if (error == ERRNO || error == MALL_ERR)
		ft_putstr_fd("ft_ls: ", 2);
	if (error == ERRNO)
	{
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	else if (error == ERRNO)
		ft_putendl_fd(strerror(errno), 2);
	if (error == USAGE || error == MALL_ERR)
		exit(EXIT_FAILURE);
	return (0);
}
