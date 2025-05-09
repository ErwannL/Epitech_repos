/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-erwann.laplante
** File description:
** my_putchar
*/

#include "my_rpg.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
