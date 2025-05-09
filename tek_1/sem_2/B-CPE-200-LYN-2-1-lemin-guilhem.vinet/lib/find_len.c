/*
** EPITECH PROJECT, 2021
** find_len
** File description:
** find len of str
*/

#include "lemin.h"

int find_len(char *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i ++) {
        len ++;
    }
    return (len);
}
