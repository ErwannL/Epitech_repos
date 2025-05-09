/*
** EPITECH PROJECT, 2022
** private_palindrome
** File description:
** utilities
*/

#include "lib.h"

int my_str_is_int(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 84;
    }
    return 0;
}

int my_str_to_int(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        nb = (10 * nb) + (str[i] - 48);
    }
    return nb;
}

char *my_revstr(char *str)
{
    char substitute;
    int length = 0;

    if (str == 0) {
        return 0;
    }
    for (; str[length] != '\0'; length++);
    length -= 1;
    for (int i = 0; i < length; i++, length--) {
        substitute = str[i];
        str[i] = str[length];
        str[length] = substitute;
    }
    return str;
}

char *int_to_str(int nb)
{
    char *str = NULL;
    int i = 0;
    int val = 0;

    for (int save = nb; save != 0; i++, save /= 10);
    str = (char *)malloc(sizeof(char) * (i + 2));
    for (int quotient = 0, rest = 0; nb > 9; val++) {
        rest = nb % 10;
        quotient = nb / 10;
        str[val] = (rest + 48);
        nb = quotient;
    }
    str[val] = (nb + 48);
    val++;
    str[i] = '\0';
    return my_revstr(str);
}
