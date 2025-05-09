/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** calcul3
*/

#include"include/my.h"
#include <unistd.h>
#include <stdlib.h>

void exit_function(void)
{
    write(2, SYNTAX_ERROR_MSG, 12);
    exit(84);
}
