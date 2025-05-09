/*
** EPITECH PROJECT, 2021
** score
** File description:
** score settings
*/

#include "my_rpg.h"

int my_getnbr(char const *str, int i)
{
    int number = 0;

    while (str[i] != '\0') {
        if (str[i] >= 47 && str[i] < 58) {
            number = number * 10 + str[i] - 48;
        } else {
            return (number);
        }
        i++;
    }
    return (number);
}

char *my_evil_str(char *str)
{
    int i, temp, len;
    len = my_strlen(str);
    int j = len - 1;

    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
    str[len] = '\0';
    return (str);
}

char *my_getstr(int nb)
{
    char *str = malloc(sizeof(char) + 1);
    int nb_mod = 0;
    int i = 0;

    if (nb < 0) {
        i++;
        str[0] = '-';
        nb = nb * -1;
    }
    while (nb > 0) {
        nb_mod = nb % 10;
        str[i] = nb_mod + 48;
        nb = nb / 10;
        i++;
    }
    str[i] = '\0';
    str = my_evil_str(str);
    return (str);
}

sfText *set_update_data(char *score, sfText *text)
{
    sfText_setString(text, score);
    return (text);
}
