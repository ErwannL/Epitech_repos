/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-erwann.laplante
** File description:
** replay
*/

#include"../includes/my.h"

char *my_write_str(int nb)
{
    char *str;
    char *zero = "0";
    int i = 0;

    str = int_to_str(nb);
    while (my_strlen(str) < 10) {
        str = my_strcat(zero, str);
    }
    return str;
}

var_t replay(var_t var)
{
    int fd;
    char *buf = malloc(sizeof(char) * 11);

    buf[10] = '\0';
    fd = open("score/score_max.txt", O_RDONLY);
    read(fd, buf, 10);
    close(fd);
    for (; buf[0] == '0' && my_strlen(buf) != 1; buf++);
    if (my_strcmp(buf, int_to_str(var.score)) < 0) {
        fd = open("score/score_max.txt", O_WRONLY);
        write(fd, my_write_str(var.score), 10);
        close(fd);
    }
}
