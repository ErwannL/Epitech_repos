/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-mysokoban-erwann.laplante
** File description:
** my_str_to_word_array
*/

#include "../include/my.h"

var_t *put_in_word_array(char *str, var_t *var, int i)
{
    if (str[i] == '\n') {
        var->index++;
        var->number = 0;
    } else {
        var->map[var->index][var->number] = str[i];
        var->save_map[var->index][var->number] = str[i];
        if (str[i] == 'P') {
            var->x = var->number;
            var->y = var->index;
        }
        var->number++;
    }
    return var;
}

void my_str_to_word_array(char *str, var_t *var)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\n')
            var->line++;
    var->map = malloc(sizeof(char *) * var->line);
    var->save_map = malloc(sizeof(char *) * var->line);
    for (int i = 0; str[i]; i++) {
        if (str[i] != '\n') {
            var->count++;
        } else {
            var->map[var->index] = malloc(sizeof(char) * var->count);
            var->save_map[var->index] = malloc(sizeof(char) * var->count);
            var->index++;
            var->count = 0;
        }
    }
    var->index = 0;
    for (int i = 0; str[i]; i++)
        var = put_in_word_array(str, var, i);
}
