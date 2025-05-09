/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-BSQ-erwann.laplante
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    typedef struct variables
    {
        struct stat *st;
        int fd;
        char *buf;
        int **map;
        int height;
        int width;
        int j;
        char **result;
        int len;
        int max[3];
        int start[2];
    }variables_t;
    int my_put_nbr(int nb);
    void my_putchar(char c);
    void my_putstr(char const *str);
    int my_strlen(char *str);
    int my_get_width(char *str);
    char *my_strncpy(char *dest , char *src , int n);
    int alpha_num(char c);
    int	number_of_word(char *str);
    variables_t minimmum(variables_t var, int a, int b);
    void one_c_l(variables_t var);
    char *my_strcat(char *dest , char const *src);
    variables_t error(variables_t var);
#endif
