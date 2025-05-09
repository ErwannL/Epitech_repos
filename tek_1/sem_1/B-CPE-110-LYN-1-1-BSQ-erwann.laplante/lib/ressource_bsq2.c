/*
** EPITECH PROJECT, 2021
** CPool
** File description:
** my_get_width
*/

#include"../includes/my.h"

variables_t error(variables_t var)
{
    if (var.buf[0] == '\n' && var.buf[1] == '\n')
        exit(84);
    for (; var.buf[0] != '\n'; var.buf++)
        var.height = var.height * 10 + var.buf[0] - 48;
    var.buf++;
    for (int i = 0; var.buf[i] != '\0'; i++) {
        if (var.buf[i] != '\n' && var.buf[i] != '.' && var.buf[i] != 'o')
            exit (84);
    }
    return (var);
}
