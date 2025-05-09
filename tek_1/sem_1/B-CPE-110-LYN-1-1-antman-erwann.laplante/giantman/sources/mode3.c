/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
** File description:
** mode3
*/

#include "../include/my.h"

void put_color(char *color, int len)
{
    for (len = 0; color[len] >= '0' && color[len] <= '9'; len++)
        my_putchar(color[len]);
    my_putchar('\n');
}

variable_t display_start_file(variable_t var)
{
    for (var.i = 0, var.enter = 2; var.enter > 0; var.i++) {
        if (var.buffer[var.i] == '\n')
            var.enter--;
        my_putchar(var.buffer[var.i]);
    }
    return var;
}

variable_t mode_3(variable_t var)
{
    var = display_start_file(var);
    while (var.buffer[var.i]) {
        var.color = malloc(sizeof(char) * 4);
        var.nbr_str = malloc(sizeof(char) * 4);
        for (var.len = 0; var.buffer[var.i] != '.'; var.len++, var.i++)
            var.color[var.len] = var.buffer[var.i];
        put_color(var.color, var.len);
        var.i++;
        for (var.len = 0; var.buffer[var.i] != '\n'; var.len++, var.i++)
            var.nbr_str[var.len] = var.buffer[var.i];
        var.nbr = my_getnbr(var.nbr_str);
        for (var.nbr -= 1; var.nbr > 0; var.nbr--)
            put_color(var.color, var.len);
        var.i++;
        free(var.color);
        free(var.nbr_str);
    }
    return var;
}
