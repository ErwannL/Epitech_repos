/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD04am-erwann.laplante
** File description:
** concat
*/

#include "concat.h"

void concat_strings (const char *str1, const char *str2, char **res)
{
    *res = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    *res = strcpy(*res, str1);
    *res = strcat(*res, str2);
    return;
}

void concat_struct (concat_t *str)
{
    str->res = malloc(sizeof(char) * (strlen(str->str1) + strlen(str->str2)\
        + 1));
    str->res = strcpy(str->res, str->str1);
    str->res = strcat(str->res, str->str2);
    return;
}
