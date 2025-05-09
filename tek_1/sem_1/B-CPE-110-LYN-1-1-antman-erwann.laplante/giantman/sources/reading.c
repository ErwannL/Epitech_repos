/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
** File description:
** reading
*/

#include "../include/my.h"

variable_t make_malloc(variable_t var, char *filepath)
{
    var.st = malloc(sizeof(struct stat));
    stat(filepath, var.st);
    var.buffer = malloc(sizeof(char) * var.st->st_size);
    return var;
}

variable_t reading_file(variable_t var, char *filepath)
{
    var.error = 0;
    var.fd = open(filepath, O_RDONLY);
    if (var.fd == -1) {
        if (my_strcmp(filepath, "-h") == 0) {
            print_h();
            var.error = 42;
            return var;
        }
        my_putstr("File don't find.\n");
        var.error = 84;
        return var;
    }
    var = make_malloc(var, filepath);
    read(var.fd, var.buffer, var.st->st_size);
    return var;
}
