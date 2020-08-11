/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whats_specific.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:22:59 by ebulwer           #+#    #+#             */
/*   Updated: 2020/08/10 15:23:00 by ebulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// Определяет тип файла (папка, файл, ссылка и тп) // готово

void    ft_tools(char *str, mode_t m)
{
    if (S_ISFIFO(m))             // Канал ФИФО (аналог Пайпа)
        str[0] = 'p';
    else if (S_ISCHR(m))         // Символьный фийл (терминал и тп)
        str[0] = 'c';
    else if (S_ISBLK(m))         // Блочный файл (жетский диск)
        str[0] = 'b';
    else if (S_ISREG(m))         // Файл или хард линк, не имеет значения
        str[0] = '-';
    else if (S_ISSOCK(m))        // Сокет
        str[0] = 's';
    else if (S_ISDIR(m))         // Дирктория
        str[0] = 'd';
    else if (S_ISLNK(m))         // Ссылка
        str[0] = 'l';
}

// Получает права доступа и тип файла // готово

char    *ft_getchmod(mode_t mode)
{
    char    *str;

    str = (char *)ft_memalloc(10);
    ft_tools(str, mode);
    str[1] = ((mode & S_IRUSR)) ? 'r' : '-';        // Накладываем маску на мод (макрос)
    str[2] = ((mode & S_IWUSR)) ? 'w' : '-';
    str[3] = ((mode & S_IXUSR)) ? 'x' : '-';
    str[4] = ((mode & S_IRGRP)) ? 'r' : '-';
    str[5] = ((mode & S_IWGRP)) ? 'w' : '-';
    str[6] = ((mode & S_IXGRP)) ? 'x' : '-';
    str[7] = ((mode & S_IROTH)) ? 'r' : '-';
    str[8] = ((mode & S_IWOTH)) ? 'w' : '-';
    if (mode & S_ISVTX && S_ISDIR(mode))           // S_ISVTX - бит, дающий разрешение на удаления.  S_IXOTH - правило на исполнение для ОСТАЛЬНЫХ
        str[9] = 't';
    else if (mode & S_ISVTX)
        str[9] = 'T';
    else if (mode & S_IXOTH)
        str[9] = '-';
    str[10] = '\0';
    return (str);
}

// Обрезка по времени // Готово

char    *ft_cuttols(char *str)
{
    char    *parse1;
    char    *parse2;
    char    *tmp_year;
    char    *tmp;

    parse1 = ft_strncut(str, 4, "second");
    tmp_year = ft_strencut(str, 5, "second");
    parse2 = ft_strencut(parse1, 14, "first");
    tmp = ft_strjoin(parse2, tmp_year);
    ft_strdel(&parse1);
    ft_strdel(&parse2);
    ft_strdel(&tmp_year);
    return (tmp);
}

// Получение временного штампа о объекте // Готово

char    *ft_get_date(long int sec)
{
    long int now_time;
    char     *str;
    char     *parse1;
    char     *parse2;

    now_time = time(NULL);       // Календарное время
    str = ctime(&sec);           // Преобразит это время в убодный формат
    if (now_time - sec > 15552000 || now_time - sec < -3600)        // Округление
        return (ft_cuttols(str));
    else
    {
        parse1 = ft_strncut(str, 4, "second");
        parse2 = ft_strencut(parse1, 9, "first");
        ft_strdel(&parse1);
        return (parse2);
    }
}

// Заполняем метаданные об объекте в структуру. Берем их из str и интерпретируем в new // Готово

int     ft_whats_specific(const char *str, t_file **new, t_flags *flags)
{
    struct stat buf;
    char        *tmp_str;

    if (lstat(str, &buf) < 0)           // Закидываем данные в буфер
    {
        printf("error");
        return (0);
    }
    ft_whats_tools(new, buf.st_mode, buf.st_uid, buf.st_gid);
    (*new)->chmod = ft_getchmod(buf.st_mode);
    tmp_str = ft_itoa(buf.st_nlink);
    (*new)->numlink = ft_strdup(tmp_str);
    ft_strdel(&tmp_str);
    (*new)->blocks = buf.st_blocks;
    tmp_str = ft_itoa(buf.st_size);
    (*new)->size = ft_strdup(tmp_str);
    ft_strdel(&tmp_str);
    (*new)->last_modif = buf.st_mtime;
    (*new)->last_access = buf.st_atime;
    (*new)->date = flags->u == 1 ? ft_get_date((*new)->last_access) : ft_get_date((*new)->last_modif);
    return (1);
}