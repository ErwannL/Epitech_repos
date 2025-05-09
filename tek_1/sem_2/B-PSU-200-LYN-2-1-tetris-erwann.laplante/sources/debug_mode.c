/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** debug_mode
*/

#include "../include/my.h"

void chained_debug_mode_bis(var_t *var, tetri_t *new)
{
    var->size = var->statu->st_size;
    var->tetrimino = malloc(sizeof(char) * (var->size + 1));
    read(var->fd, var->tetrimino, var->size);
    create_node(var->dir->d_name, var->tetrimino, new);
    new->next = var->tetri;
    var->tetri = new;
    close(var->fd);
}

int chained_debug_mode(var_t *var)
{
    tetri_t *new = malloc(sizeof(tetri_t));

    if (var->dir->d_name[0] != '.' && var->num != 0) {
        var->nbr_node++;
        var->fd = open(my_strcat("tetriminos/", var->dir->d_name), O_RDONLY);
        if (var->fd == -1) {
            closedir(var->directory);
            free_all(var);
            return 84;
        }
        var->st = stat(my_strcat("tetriminos/", var->dir->d_name), var->statu);
        if (var->st == -1) {
            close(var->fd);
            closedir(var->directory);
            free_all(var);
            return 84;
        }
        chained_debug_mode_bis(var, new);
    }
    return 0;
}

int debug_mode(var_t *var)
{
    var->tetri = NULL;
    var->nbr_node = 0;
    if (!var->directory) {
        closedir(var->directory);
        free_all(var);
        return 84;
    }
    while (var->dir != NULL) {
        if (chained_debug_mode(var) == 84)
            return 84;
        var->dir = readdir(var->directory);
        var->num++;
    }
    my_putstr("Number of  tetriminos: ");
    my_put_nbr(var->nbr_node - 2);
    my_putchar('\n');
    put_name(var);
    closedir(var->directory);
    free_all(var);
    return 0;
}

int launch_debug(var_t *var)
{
    put_key(var->arg->key_left, "left");
    put_key(var->arg->key_right, "right");
    put_key(var->arg->key_turn, "turn");
    put_key(var->arg->key_drop, "drop");
    put_key(var->arg->key_quit, "quit");
    put_key(var->arg->key_pause, "pause");
    my_putstr("Next: ");
    my_putstr(var->arg->without_next == FALSE ? "Yes\n" : "No\n");
    my_putstr("Level: ");
    my_put_nbr(var->arg->level);
    my_putchar('\n');
    my_putstr("Size: ");
    my_put_nbr(var->arg->map_size[0]);
    my_putstr("*");
    my_put_nbr(var->arg->map_size[1]);
    my_putstr("\n\n");
    var->directory = opendir("tetriminos");
    return debug_mode(var);
}
