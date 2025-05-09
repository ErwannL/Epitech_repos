/*
** EPITECH PROJECT, 2021
** B-CPE-110-LYN-1-1-bsbsq-erwann.laplante
** File description:
** I - File systems -> step 1 to 5
*/

#include "../include/my.h"

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    ((fd != - 1) ? my_putstr("SUCCESS\n") : my_putstr("FAILURE\n"));
    close(fd);
    return (0);
}

void fs_understand_return_of_read(int fd , char *buffer , int size)
{
    int res = read(fd, buffer, size);

    ((res == - 1) ? (my_putstr("read failed\n")) : ((res == 0) ? \
    (my_putstr("read has nothing more to read\n")) : ((res < size) ? \
    (my_putstr("read didn’t complete the entire buffer\n")) : \
    (my_putstr("read completed the entire buffer\n")))));
}

void fs_cat_500_bytes(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size = 500;
    char buffer[size];

    ((fd != - 1) ? (read(fd, buffer, size), my_putstr(buffer), close(fd)) : \
    (close(fd)));
}

void fs_cat_x_bytes(char const *filepath , int x)
{
    int fd = open(filepath, O_RDONLY);
    int size = x;
    char buffer[size];

    ((fd != - 1) ? (read(fd, buffer, size), my_putstr(buffer), close(fd)) : \
    (close(fd)));
}

void fs_print_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size = 10000;
    char buffer[size];
    int i;

    if(fd != - 1) {
        read(fd, buffer, size);
        while (buffer[i] != '\n') {
            my_putchar(buffer[i]);
            i++;
        }
    }
    close(fd);
}
