/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-erwann.laplante
** File description:
** put
*/

#include "../include/my.h"

void put_key(int key, char *name)
{
    my_putstr("Key ");
    my_putstr(name);
    my_putstr(": ");
    if (key == 258)
        my_putstr("KEY_DOWN");
    if (key == 259)
        my_putstr("KEY_UP");
    if (key == 260)
        my_putstr("KEY_LEFT");
    if (key == 261)
        my_putstr("KEY_RIGHT");
    if (key < 258 || key > 261)
        my_putchar(key);
    my_putstr(" (");
    my_put_nbr(key);
    my_putstr(")\n");
}

void cond_put_name_for(tetri_t *cursor)
{
    for (int j = 0; j < cursor->height; j++) {
        for (int i = 0; i < cursor->width; i++)
            my_putchar(cursor->patern[j][i]);
        my_putchar('\n');
    }
}

int cond_put_name(tetri_t *cursor, int chara)
{
    if (cursor->name[0] == chara) {
        my_putstr("Tetriminos '");
        my_putstr(cursor->name);
        my_putstr("': ");
        if (cursor->width == -84)
            return 84;
        my_putstr("size ");
        my_put_nbr(cursor->width);
        my_putstr("*");
        my_put_nbr(cursor->height);
        my_putstr(", color ");
        my_put_nbr(cursor->color);
        my_putchar('\n');
        cond_put_name_for(cursor);
    }
    return 0;
}

void put_name_while(var_t *var, tetri_t *cursor, int chara)
{
    while (cursor != NULL) {
        if (cond_put_name(cursor, chara) == 84)
            my_putstr("error\n");
        cursor = cursor->next;
    }
}

void put_name(var_t *var)
{
    tetri_t *cursor;

    for (int chara = 0; chara < 127; chara++) {
        cursor = var->tetri;
        put_name_while(var, cursor, chara);
    }
}
