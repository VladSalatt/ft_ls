cmake_minimum_required(VERSION 3.16)
project(my_ls C)

set(CMAKE_C_STANDARD 11)

add_executable(my_ls
        ft_ls.c
        ft_ls.h
        flags.c)
