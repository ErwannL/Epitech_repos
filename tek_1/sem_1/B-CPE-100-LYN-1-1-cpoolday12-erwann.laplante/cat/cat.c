/*
** EPITECH PROJECT, 2021
** Task 01 - Cat
** File description:
** description
*/
#include "../lib/my/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

char *clean_buffer(char *buffer)
{
    for (int i = 0; i < 32; i++)
        buffer[i] = 0;
    return (buffer);
}

char find_error(int val, int erreur)
{
    val = errno;

    if (errno == ENOENT) {
        write(2, "cat: test: No such file or directory", 37);
        erreur = 84;
    }
    if (errno == EACCES) {
        write(2, "cat: test: Permission denied", 29);
        erreur = 84;
    }
    if (errno == EISDIR) {
        write(2, "cat: test: Is a directory", 26);
        erreur = 84;
    }
    return (erreur);
}

void if_one(char buffer, int ac)
{
    while (ac == 1) {
        read(0, buffer, 32);
        my_putstr(buffer);
        clean_buffer(buffer);
    }
}

int main(int ac, char **av)
{
    char buffer[32];
    int result_open = 0;
    int erreur = 0;

    if_one(buffer, ac);
    for (int i = 1; i < ac; i++) {
        result_open = open(av[i], O_RDONLY);
        while (read(result_open, buffer, 32) != 0) {
            buffer[32] = 0;
            my_putstr(buffer);
            clean_buffer(buffer);
        }
    erreur = find_error(errno , erreur);
    close(result_open);
    }
    return (erreur);
}
