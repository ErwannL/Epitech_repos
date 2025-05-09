/*
** EPITECH PROJECT, 2021
** str_cmp
** File description:
** compare two string and if it's equal or not
*/

#include "lemin.h"

int str_cmp(char *str1, char *str2)
{
    if (str1 == NULL || str2 == NULL)
        return (84);
    for (int i = 0; i < find_len(str2); i ++) {
        if (str1[i] == str2[i]) {
        } else
            return (1);
    }
    return (0);
}
