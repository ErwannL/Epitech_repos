/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
** File description:
** mode3
*/

#include "../include/my.h"

variable_t find_color(variable_t var)
{
    var.color = malloc(sizeof(char) * 4);
    for (var.len_color = 0; var.buffer_com[var.i] != '\n'
    ; var.len_color++, var.i++)
        var.color[var.len_color] = var.buffer_com[var.i];
    var.color[var.len_color] = var.buffer_com[var.i];
    return var;
}

variable_t buffer_next(variable_t var, int enter, int j)
{
    free(var.buffer);
    for (var.i = 0, j = 0, enter = 2; enter > 0; var.i++, j++) {
        if (var.buffer_com[var.i] == '\n')
            enter--;
        var.buffer_end[j] = var.buffer_com[var.i];
    }
    return var;
}

variable_t buffer_next_2(variable_t var)
{
    if (var.buffer[var.i] == '#') {
        while (var.buffer[var.i] != '\n')
            var.i++;
        var.i++;
    }
    var.buffer_com[var.j] = var.buffer[var.i];
    return var;
}

variable_t buffer_without_commit(variable_t var)
{
    int enter;

    var.buffer_com = malloc(sizeof(char) * var.st->st_size);
    var.buffer_end = malloc(sizeof(char) * var.st->st_size);
    for (var.i = 0, var.j = 0; var.buffer[var.i]; var.i++, var.j++)
        var = buffer_next_2(var);
    var = buffer_next(var, enter, var.j);
    return var;
}

variable_t mode_3(variable_t var)
{
    int i = 0;
    int len = 0;
    int enter = 2;

    var.ident = 0;
    var.fd2 = open(".endfile.txt", O_CREAT | O_WRONLY);
    var = buffer_without_commit(var);
    for (i = 0; enter > 0; i++) {
        if (var.buffer_end[i] == '\n')
            enter--;
        len++;
    }
    for (i = 0; len > 0; len--, i++)
        my_putchar(var.buffer_end[i]);
    free(var.buffer_end);
    while (var.buffer_com[var.i])
        var = while_mode3(var);
    return var;
}
