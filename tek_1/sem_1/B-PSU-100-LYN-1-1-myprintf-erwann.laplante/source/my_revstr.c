/*
** EPITECH PROJECT, 2021
** MY_REVSTR
** File description:
** reverse str
*/

#include"../includes/my.h"

char *my_rev_str(char *str)
{
    char var;
    int i;
    int j;

    for (i = 0; str[i] != '\0'; i++);
    for (j = 0; j < i; i--, j++) {
        var = str[j];
        str[j] = str[i - 1];
        str[i - 1] = var;
    }
    return (str);
}
