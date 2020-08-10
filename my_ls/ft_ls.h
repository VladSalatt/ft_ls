/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:00:51 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/10 19:26:55 by ebulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <pwd.h>
# include <grp.h>

typedef struct      s_flags
{
    int             l;          // Выдает в одноколоночном формате основные данные о файлах
    int             R;          // Рекурсивная выдача списка фалов и каталогов
    int             a;          // Показывает скрытые файлы
    int             t;          // Сортировка по временному штампу
    int             r;          // Сортировка в обратном порядке
    int             u;          // Сортировка по времени последнего доступа к файлу
    int             f;          // Не сортировать содержимое каталога; выдавать файлы в том порядке, в котором они записаны на диск.
                                // Эта опция также разрешает -a и -U и запрещает -l, --color, -s, и -t, если они были заданы перед -f.
    int             g;          // Игнорируется; нужна для совместимости с Unix.
}                   t_flags;

typedef struct      s_file
{
    char            *name;
    char            *path;
    int             type;
    char            *time;
    char            *username;
    char            *groupname;
    char            *chmod;
    char            *size;
    struct s_file    *next;
}                   t_file;

int     ft_is_it_flag(const char *s);
int     ft_putflag(const char *av, t_flags *flags);
int     ft_find_flags(const char **av, int ac, t_flags *flags);
int     ft_valid_flag(const char *s, char *v);
static int      ft_only_flags(const char **av);
void    ft_recursion_penetration(const char *path, t_flags *flags, int path_flag);
void    ft_print_path(const char *path);
t_file      *ft_get_rootnames(t_file **head, const char *path, t_flags *flags);
int     ft_can_add_hidden_file(const char *str, t_flags *flags)




#endif
