/*
** EPITECH PROJECT, 2021
** Task 0
** File description:
** print char
*/
#include<unistd.h>
#include"my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
