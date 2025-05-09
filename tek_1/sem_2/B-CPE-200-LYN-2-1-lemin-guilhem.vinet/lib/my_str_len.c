/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** my_str_len
*/

#include "lemin.h"

int my_strlen(char const *str)
{
    int length = 0;

    for (int i = 0; str[i] != '\0'; str++) {
        length++;
    }
    return length;
}
