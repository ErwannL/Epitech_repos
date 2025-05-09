/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** color
*/

#include "../include/c_test.h"

void red(void)
{
    printf("\033[1;31m");
}

void green(void)
{
    printf("\033[0;32m");
}

void reset(void)
{
    printf("\033[0m");
}
