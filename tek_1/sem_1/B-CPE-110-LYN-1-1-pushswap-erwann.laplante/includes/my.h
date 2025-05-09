/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-BSQ-erwann.laplante
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    int my_put_nbr(int nb);
    void my_putchar(char c);
    int my_getnbr(char *str);
    int is_sort(int ac, char **av);
    void my_putstr(char const *str);
    char **move_av(int ac, char **av);
    int check_error(int ac, char **av);
    char **move_back_av(int ac, char **av);
    int find_min(int ac, char **av, int min);
#endif
