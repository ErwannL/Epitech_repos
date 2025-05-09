/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** chained
*/

#include "../include/my.h"

void bad_tet_or_not(var_t *var, tetri_t *new)
{
    if (new->width != -84) {
        new->next = var->tetri;
        var->tetri = new;
    } else
        var->tetri = var->tetri;
    close(var->fd);
}

int cond_init_chained(var_t *var)
{
    tetri_t *new;

    if (var->dir->d_name[0] != '.' && var->num != 0) {
        var->nbr_node++;
        new = malloc(sizeof(tetri_t));
        var->fd = open(my_strcat("tetriminos/", var->dir->d_name), O_RDONLY);
        if (var->fd == -1)
            return 84;
        var->st = stat(my_strcat("tetriminos/", var->dir->d_name), var->statu);
        if (var->st == -1) {
            close(var->fd);
            return 84;
        }
        var->size = var->statu->st_size;
        var->tetrimino = malloc(sizeof(char) * (var->size + 1));
        read(var->fd, var->tetrimino, var->size);
        create_node(var->dir->d_name, var->tetrimino, new);
        bad_tet_or_not(var, new);
    }
    return 0;
}

int init_chained(var_t *var)
{
    int cond = 0;

    var->directory = opendir("tetriminos");
    var->tetri = NULL;
    var->nbr_node = 0;
    if (!var->directory)
        return 84;
    while (var->dir != NULL) {
        cond = cond_init_chained(var) == 84;
        if (cond == 84) {
            closedir(var->directory);
            free_all(var);
            return 84;
        } else
            var->num++;
        var->dir = readdir(var->directory);
    }
    closedir(var->directory);
    return 0;
}
