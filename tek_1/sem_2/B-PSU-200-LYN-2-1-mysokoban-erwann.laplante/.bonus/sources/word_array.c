/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-mysokoban-erwann.laplante
** File description:
** word_array
*/

#include "../include/my.h"

char **find_o(char **save, int max, char **map)
{
    int i = 0;
    int j = 0;

    while (i < max) {
        j = 0;
        while (save[i][j] != '\0') {
            (save[i][j] == 'O' && map[i][j] == ' ') ? map[i][j] = 'O' : 0;
            j = j + 1;
        }
        i = i + 1;
    }
    return map;
}

void print_map(char **map, var_t *var)
{
    int i = 0;

    clear();
    while (i < var->index) {
        printw(map[i]);
        printw("\n");
        i++;
    }
    refresh();
}

var_t *cpy_word_array(var_t *var)
{
    int i = 0;

    while (i < var->index) {
        var->save_map[i] = my_strcpy(var->save_map[i], var->map[i]);
        i++;
    }
    return var;
}

var_t *reset_map(var_t *var)
{
    int i = 0;

    while (i < var->index) {
        var->map[i] = my_strcpy(var->map[i], var->save_map[i]);
        i++;
    }
    return var;
}

int check_win(char **save, int max, char **map)
{
    int i = 0;
    int j = 0;
    int val = 0;

    while (i < max) {
        j = 0;
        while (save[i][j] != '\0') {
            (save[i][j] == 'O' && map[i][j] != 'X') ? val = 1 : 0;
            j = j + 1;
        }
        if (val == 1)
            return 1;
        i = i + 1;
    }
    return 0;
}
