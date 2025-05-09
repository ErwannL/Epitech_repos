/*
** EPITECH PROJECT, 2021
** Task 07 - my_put_nbr
** File description:
** This fill displays the number given as a parameter
*/

#include"../include/my.h"

int is_neg(char *number)
{
    if (number[0] == '-')
        return (1);
    else
        return (0);
}
