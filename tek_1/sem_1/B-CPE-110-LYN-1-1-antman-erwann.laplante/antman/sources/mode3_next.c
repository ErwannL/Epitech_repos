/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
** File description:
** mode3_next
*/

#include "../include/my.h"

variable_t boucle_mode3_next(variable_t var)
{
    if (var.ident == 0)
        var.nbr++;
    else {
        write(1, var.color, my_strlen(var.color) - 1);
        write(1, ".", 1);
        write(1, nbr_str(var.nbr), my_intlen(var.nbr));
        write(1, "\n", 1);
    }
    return var;
}

variable_t boucle_mode3(variable_t var)
{
    for (var.len_color = 0; var.color[var.len_color];) {
        if (var.buffer_com[var.i] == var.color[var.len_color]) {
            var.i++;
            var.len_color++;
        } else if (var.color[var.len_color] == '\n' &&
        var.buffer_com[var.i] == '\0' && var.ident == 0) {
            var.ident = 0;
            var.len_color++;
        } else {
            var.len_color = 5;
            var.ident = 1;
        }
    }
    var = boucle_mode3_next(var);
    return var;
}

variable_t while_mode3(variable_t var)
{
    var = find_color(var);
    var.i++;
    var.nbr = 1;
    var.ident = 0;
    while (var.ident == 0)
        var = boucle_mode3(var);
    free(var.color);
    return var;
}
