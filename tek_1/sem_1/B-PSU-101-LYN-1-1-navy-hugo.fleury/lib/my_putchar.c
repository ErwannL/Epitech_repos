/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** description
*/

#include <unistd.h>

void my_putchar(char c, int x)
{
    write(x, &c, 1);
}
