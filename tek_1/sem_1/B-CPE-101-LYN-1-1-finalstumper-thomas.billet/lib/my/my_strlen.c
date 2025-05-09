/*
** EPITECH PROJECT , $YEAR
** $NAME_OF_THE_PROJECT
** File description:
** No file there , just an epitech header example
*/
#include "../../include/rush3.h"

int my_strlen(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        a = a + 1;
    }
    return (a);
}