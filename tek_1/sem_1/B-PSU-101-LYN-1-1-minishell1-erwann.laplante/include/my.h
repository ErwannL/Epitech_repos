/*
** EPITECH PROJECT, 2022
** B-PSU-101-LYN-1-1-minishell1-erwann.laplante
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #define INT_MAX (2147483647)
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <stdio.h>
    typedef struct variable {
        int line;
        int argc;
        char *buf;
        char *home;
        char *here;
        char *before;
        char *buf_temp;
        char *buf_temp2;
        char **env;
        char **argv;
        pid_t pid;
        size_t size;
        int dir;
    } var_t;
    char *int_to_str(int nb);
    int my_intlen(int nbr);
    int my_put_nbr(int nb);
    void my_putchar(char c);
    int my_putstr(char const *str);
    char *my_revstr(char *str);
    char *my_strcat(char *dest, char *src);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest , char const *src);
    int my_strlen(char const *str);
    char *my_strncpy(char *dest , char const *src, int n);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *del_space(char *str);
    char *get_home(char **env);
    char *setup_home(char *home, char **env);
    var_t *init_struct(var_t *var, int argc, char **argv, char **env);
    var_t *pwd_f(var_t *var);
    var_t *cd_f(var_t *var);
    var_t *ls_f(var_t *var);
    var_t *setup_here(var_t *var);
#endif
