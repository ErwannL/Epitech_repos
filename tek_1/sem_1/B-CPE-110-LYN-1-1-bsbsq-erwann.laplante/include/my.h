/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-bsbsq-erwann.laplante
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdlib.h>
    int my_put_nbr(int nb);
    void my_putchar(char c);
    int my_putstr(char const *str);
    char *my_strdup(char const *src);
    char *my_strcat(char *dest, char const *src);
    int my_strlen(char const *str);
    int fs_open_file(char const *filepath);
    void fs_understand_return_of_read(int fd , char *buffer , int size);
    void fs_cat_500_bytes(char const *filepath);
    void fs_cat_x_bytes(char const *filepath , int x);
    void fs_print_first_line(char const *filepath);
    int fs_get_number_from_first_line(char const *filepath);
    void array_1d_print_chars(char const *arr);
    void array_1d_print_ints(int const *arr , int size);
    int array_1d_sum(int const *arr , int size);
    int array_2d_sum(char **arr , int nb_rows , int nb_cols);
#endif
