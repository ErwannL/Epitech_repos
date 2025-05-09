/*
** EPITECH PROJECT, 2022
** B-PSU-101-LYN-1-1-minishell1-erwann.laplante
** File description:
** my_putchar
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
