/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** struct
*/

#include "../include/my.h"

var_t *init_struct_bis(var_t *var)
{
    var->a = 1;
    var->b = 1;
    var->full = 0;
    var->cursor = var->tetri;
    var->n = 0;
    var->destroy_line = var->arg->level;
    var->speed = 10 - var->destroy_line / 10;
    var->stat = GAME;
    var->next_n = 0;
    var->next_cursor = var->tetri;
    return var;
}

var_t *init_struct(var_t *var)
{
    var->my_win = malloc(sizeof(WINDOW));
    var->arg = malloc(sizeof(arg_t));
    var->arg->map_size = malloc(sizeof(int) * 3);
    var->arg->level = 1;
    var->arg->key_left = KEY_LEFT;
    var->arg->key_right = KEY_RIGHT;
    var->arg->key_turn = KEY_UP;
    var->arg->key_drop = KEY_DOWN;
    var->arg->key_quit = 'q';
    var->arg->key_pause = ' ';
    var->arg->map_size[0] = 20;
    var->arg->map_size[1] = 10;
    var->arg->without_next = FALSE;
    var->dir = malloc(sizeof(struct dirent));
    var->fd = 0;
    var->st = 0;
    var->statu = malloc(sizeof(struct stat));
    var->size = 0;
    var->num = 0;
    return init_struct_bis(var);
}

void free_all(var_t *var)
{
    free(var->my_win);
    free(var->arg->map_size);
    free(var->arg);
    free(var->dir);
    free(var->statu);
    free(var);
}
