/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
** File description:
** mode1
*/

#include "../include/my.h"

variable_t mode_1(variable_t var)
{
    int i;

    var.my_list = malloc(sizeof(dlist_t));
    var.sorted_list = malloc(sizeof(dlist_t));
    var.my_list->start = NULL;
    add_after(var.my_list, '\0');
    add_after(var.sorted_list, '\0');
    for (i = 0; var.buffer[i]; i++)
        browse_list_add(var.my_list, var.buffer[i]);
    sorting_list(var.my_list, var.sorted_list, var);
    browse(var.sorted_list);
    free(var.buffer);
    return var;
}
