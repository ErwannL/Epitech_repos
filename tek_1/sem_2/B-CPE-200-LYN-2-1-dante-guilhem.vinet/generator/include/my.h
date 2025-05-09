/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-dante-guilhem.vinet
** File description:
** my
*/

#ifndef MY_H_

    //define

    #define MY_H_
    #define TRUE 0
    #define FALSE 1

    //include

    #include <stdlib.h>
    #include <unistd.h>
    #include <time.h>

    //struct

    typedef struct var {
        int size_x;
        int size_y;
        int perfect;
        char **maze;
        int random;
        int i;
        int j;
        int finish;
        int unperfect;
        int rand_ok;
    } var_t;

    //lib

    char *int_to_str(int nb);
    int my_put_nbr(int nb);
    void my_putchar(char c);
    int my_putstr(char const *str);
    char *my_revstr(char *str);
    char *my_strcat(char *dest, char *src);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest , char const *src);
    int my_strlen(char const *str);
    int my_is_num(char *str);
    int my_str_to_int(char *str);

    //src

    int main(int argc, char **argv);
    var_t *create_maze(var_t *var);
    void print_maze(var_t *var);
    var_t *create_path(var_t *var);
    var_t *create_fake(var_t *var, int i, int j);
    var_t *create_fake_six(var_t *var, int i, int j);
    var_t *check_condition(var_t *var, int i, int j, int n);

#endif
