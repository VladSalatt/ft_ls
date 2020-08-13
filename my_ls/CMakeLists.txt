cmake_minimum_required(VERSION 3.16)
project(my_ls C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(libft)

add_executable(my_ls
        libft/ft_strdel.c
        libft/ft_strjoin.c
        libft/ft_strcmp.c
        libft/ft_putchar.c
        libft/ft_putstr.c
        libft/ft_putendl.c
        libft/ft_strlen.c
        libft/ft_strdup.c
        libft/ft_memalloc.c
        libft/ft_bzero.c
        libft/ft_itoa.c
        ft_ls.c
        ft_ls.h
        flags.c
        ft_addsymb.c
        ft_free_list.c
        ft_strencut.c
        ft_strncut.c
        init.c
        print.c
        print_2.c
        print_total.c
        push_back.c
        whats_specific.c
        struct_filenames.c
        sort.c
        recursion.c
        restruct.c)
