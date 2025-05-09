/*
** EPITECH PROJECT, 2021
** eval_expr
** File description:
** eval expr
*/
#include"my.h"
#include"stdlib.h"

char *reset(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = '\0';
    return (str);
}
