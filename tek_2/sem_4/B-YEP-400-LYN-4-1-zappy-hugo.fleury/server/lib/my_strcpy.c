/*
** EPITECH PROJECT, 2022
** strcpy
** File description:
** cpy
*/

#include "../include/my_teams.h"

char *my_strcpy(char *str, int is_free)
{
    int len = strlen(str);
    char *tmp = malloc(sizeof(char) * (len + 1));
    int i = 0;

    for (; str[i] != '\0'; i++)
        tmp[i] = str[i];
    tmp[i] = '\0';
    is_free ? free(str) : 0;
    return (tmp);
}
