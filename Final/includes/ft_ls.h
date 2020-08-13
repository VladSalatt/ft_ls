/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:00:51 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/09 16:00:53 by ebulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdlib.h>
# include "libft.h"
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <limits.h>
# include <errno.h>

# define T_FILE 1               // Использовал для макросов S_ISREG ...
# define T_DIR  2
# define T_LINK 3

enum	{ERRNO, USAGE, MALL_ERR};

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
    char            *date;
    char            *username;
    char            *groupname;
    char            *chmod;
    char            *size;
    char            *numlink;
    long long int   blocks;
    long long int   last_modif;
    long long int   last_access;
    struct s_file    *next;
}                   t_file;

int		ls_error(char *s, int error);
t_file 	*ls_free_list(t_file **List_to_free);
void 	ft_init(t_file *head, char **av, t_flags *flags);
int 	ft_is_only_arg(t_file *head);
void 	ft_print_without_dir(t_file **head);
t_file 	*ft_struct_filenames(t_file **head, const char **av, const char *path, t_flags *flags);
void 	ft_recursion_init(t_file *head, const char **av, t_flags *flags);
void 	ft_print_dir(char *path, t_flags *flags);
char 	*ft_get_path(char *name, char *path);
void 	ft_print_total(t_file **head);
void 	ft_print_struct(t_file **head, t_flags *flags);
t_file	*ft_restruct(t_file **head);
char 	*ft_addsymbend(char *str, char c, int num);
char 	*ft_addsymb(char *str, char c, int num);
void 	ft_print_flag_l(t_file **head, t_flags *flags);
char	*ft_strencut(char *str, int n, char *choice);
char    *ft_strncut(char *str, int n, char *choice);
void    ft_content_cpy(t_file *src, t_file *dst);
void    ft_sort_list(t_file **head, t_flags *flags);
void    ft_push_back(t_file **head, t_file *new);
void    ft_tools(char *str, mode_t m);
void    ft_whats_tools(t_file **new, mode_t mode, uid_t uid, gid_t gid);
int     ft_is_it_flag(const char *s);
int     ft_putflag(const char *av, t_flags *flags);
int     ft_find_flags(const char **av, int ac, t_flags *flags);
int     ft_valid_flag(const char *s, char *v);
void    ft_recursion_penetration(const char *path, t_flags *flags, int path_flag);
void    ft_print_path(const char *path);
t_file      *ft_get_rootnames(t_file **head, const char *path, t_flags *flags);
int     ft_can_add_hidden_file(const char *str, t_flags *flags);
t_file    *ft_new_list(t_file *new, const char *name, const char *path, t_flags *flags);
int     ft_whats_specific(const char *str, t_file **new, t_flags *flags);



#endif
