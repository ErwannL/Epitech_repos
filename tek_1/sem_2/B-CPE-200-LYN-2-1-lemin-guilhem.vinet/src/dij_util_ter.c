/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** dij_util_ter
*/

#include "lemin.h"

dij_t *rm_node(dij_t *diji)
{
    for (int y = diji->stop; y != diji->nbr_node; y++) {
        diji->path[y] = my_revstr(diji->path[y]);
        for (int x = 0; diji->path[y][x] != ' ' && diji->path[y][x] != '\0'
        && diji->path[y][x]; diji->path[y]++);
        diji->path[y]++;
        diji->path[y] = my_revstr(diji->path[y]);
    }
    return diji;
}

char *no_next(dij_t *diji, char *now_next, int i)
{
    if (my_strcmp(diji->nodes[i].name, diji->now_name) == 0) {
        if (diji->nodes[i].next == NULL)
            return NULL;
        now_next = malloc(sizeof(char) * (my_strlen(diji->nodes[i].next)
        + 1));
        now_next = my_strcpy(now_next, diji->nodes[i].next);
    }
    return now_next;
}
