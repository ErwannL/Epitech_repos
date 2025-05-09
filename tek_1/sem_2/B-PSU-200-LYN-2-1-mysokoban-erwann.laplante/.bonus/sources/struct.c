/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-mysokoban-erwann.laplante
** File description:
** struct
*/

#include "../include/my.h"

var_t *init_struct(var_t *var, char **argv)
{
    var->line = 0;
    var->count = 0;
    var->index = 0;
    var->number = 0;
    var->start_x = var->x;
    var->start_y = var->y;
    var->fd = open(argv[1], O_RDONLY);
    stat(argv[1], &var->buf);
    var->size = var->buf.st_size;
    var->buf_map = malloc(sizeof(char) * (var->size + 1));
    read(var->fd, var->buf_map, var->size);
    var->r_val = 1;
    var->ex_num = 0;
    return var;
}

void free_all(var_t *var)
{
    free(var->my_win);
    free(var->buf_map);
    free(var->map);
    free(var->save_map);
}
