/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** affiche un caractère
*/

#include "lemin.h"

void my_putchar (char c)
{
    write(1, &c, 1);
}
