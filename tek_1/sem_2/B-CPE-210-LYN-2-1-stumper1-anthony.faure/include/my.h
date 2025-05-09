/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper1-anthony.faure
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stdlib.h>
    void my_putchar(char c, int fd);
    int my_putstr(char const *str, int fd);
    int my_strlen(char const *str);
    int check_errors(char **argv);
    int error_arg(void);
    int my_atoi(char *str);
    char *my_strcpy(char *dest , char const *src);
    int my_strcmp(char const *s1, char const *s2);
    int fractals(char **fst, char **scd, int flag, int nb);
#endif
