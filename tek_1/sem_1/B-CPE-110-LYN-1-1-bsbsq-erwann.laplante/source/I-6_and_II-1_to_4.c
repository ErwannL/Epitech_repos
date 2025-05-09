/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-bsbsq-erwann.laplante
** File description:
** I - File systems -> step 6 && II - 2d arrays -> step 1 to 4
*/

#include "../include/my.h"

int fs_get_number_from_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size = 10000;
    char buf[size];
    char str[size];

    str[0] = '\0';
    if(fd != - 1) {
        read(fd, buf, size);
        for (int i = 0, j = 0; buf[i] != '\n'; i++)
            ((buf[i] >= '0' && buf[i] <= '9') ? (str[j] = buf[i], j++) : (j));
        close(fd);
        my_putstr(str);
        if (str[0] == '\0')
            return (-1);
    } else {
        close(fd);
        return (-1);
    }
    return (0);
}

void array_1d_print_chars(char const *arr)
{
    for (int i = 0; arr[i] != '\0'; i++) {
        my_putchar(arr[i]);
        my_putchar('\n');
    }
}

void array_1d_print_ints(int const *arr , int size)
{
    for (int i = 0; i != size; i++) {
        my_put_nbr(arr[i]);
        my_putchar('\n');
    }
}

int array_1d_sum(int const *arr , int size)
{
    int res = 0;

    for (int i = 0; i != size; i++)
        res += arr[i];
    return (res);
}

int array_2d_sum(char **arr , int nb_rows , int nb_cols)
{
    int res = 0;

    for (int i = 0; i != nb_rows; i++) {
        for (int j = 0; j != nb_cols; j++)
            res += arr[i][j];
    }
    return (res);
}
