/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** Capitalizes the first letter of each word.
*/

#include "my.h"

char *my_strcapitalize(char *str, int what)
{
    char *dup = my_strdup(str);

    for (int i = 0; dup[i] != '\0'; i++) {
        if (what == 0) {
            dup[i] += ((dup[i] >= 65) && (dup[i] <= 90) ? 32 : 0);
        } else {
            dup[i] -= ((dup[i] >= 97 && dup[i] <= 122) ? 32 : 0);
        }
    }
    return dup;
}
