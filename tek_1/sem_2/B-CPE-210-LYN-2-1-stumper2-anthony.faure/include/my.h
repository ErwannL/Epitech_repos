/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper2-anthony.faure
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    typedef struct var {
        int width;
        int height;
        char p1;
        char p2;
        char ref;
        char **map;
        int player;
        int nb;
    } var_t;
    void my_putchar(char c, int fd);
    int my_putstr(char const *str, int fd);
    int my_strlen(char const *str);
    char *my_strcpy(char *dest , char const *src);
    int my_strcmp(char const *s1, char const *s2);
    int my_atoi(char *str);
    void fill_vars(var_t *vars);
    int options(var_t *vars, char **argv, int argc);
    var_t *creat_map(var_t *var);
    void print_map(var_t *var);
    int is_a_tie(var_t *var);
    int print_error(void);
    int check_victory(var_t *var);
    int print_tie(var_t *vars, char *str);
    int print_vic(var_t *vars, char *str);
    void print_ask(var_t *vars);
    int my_getnbr(char *str);
#endif
