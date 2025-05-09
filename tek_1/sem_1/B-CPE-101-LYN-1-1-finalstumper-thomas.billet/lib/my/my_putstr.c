/*
** EPITECH PROJECT , $YEAR
** $NAME_OF_THE_PROJECT
** File description:
** No file there , just an epitech header example
*/
#include "../../include/rush3.h"

void my_putstr(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a = a + 1;
    }
}
