/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** nodes
*/

#include "../include/my.h"

void create_node_bis(char *name, char *tet, tetri_t *new, int j)
{
    for (int height = 0; height < new->height; height++)
        new->patern[height] = malloc(sizeof(char) * new->width);
    for (int width = 0, lenght = 0; tet[j]; j++, lenght++) {
        if (lenght > new->width) {
            lenght = 0;
            width++;
        }
        new->patern[width][lenght] = tet[j];
    }
}

void create_node(char *name, char *tet, tetri_t *new)
{
    int j = 0;
    int lenght = 0;

    for (int i = 0; name[i] != '.' && name[i] != '\0'; i++, lenght++);
    new->name = malloc(sizeof(char) * lenght);
    for (lenght = 0; name[lenght] != '.' && name[lenght] != '\0'; lenght++)
        new->name[lenght] = name[lenght];
    if (good_tetrimino(tet) == 84 || name[lenght] == '\0') {
        new->width = -84;
        return;
    }
    for (; tet[j] != ' ' && tet[j]; new->width = tet[j] - 48, j++);
    j++;
    for (; tet[j] != ' ' && tet[j]; new->height = tet[j] - 48, j++);
    j++;
    for (; tet[j] != '\n' && tet[j]; new->color = tet[j] - 48, j++);
    j++;
    new->patern = malloc(sizeof(char *) * new->height);
    create_node_bis(name, tet, new, j);
}
