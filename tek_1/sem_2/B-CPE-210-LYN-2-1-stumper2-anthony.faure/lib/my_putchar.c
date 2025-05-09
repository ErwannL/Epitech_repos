/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper2-anthony.faure
** File description:
** my_putchar
*/

#include "../include/my.h"

void my_putchar(char c, int fd)
{
    write(fd, &c, 1);
}
