/*
** EPITECH PROJECT , $YEAR
** $NAME_OF_THE_PROJECT
** File description:
** No file there , just an epitech header example
*/
#include <unistd.h>
#include "../../include/rush3.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
