/*
** EPITECH PROJECT, 2021
** Task 0
** File description:
** Print char
*/

#include"../includes/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
