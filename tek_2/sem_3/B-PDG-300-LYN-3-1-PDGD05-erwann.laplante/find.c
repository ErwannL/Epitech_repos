/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD05-erwann.laplante
** File description:
** find
*/

#include "string.h"

int find_s (const string_t *this, const string_t *str, size_t pos)
{
    char *new = malloc(sizeof(char) * (strlen(this->str) + 1));
    char *test;
    int res = 0;
    int j = 0;

    for (int i = pos; this->str[i]; i++, j++)
        new[j] = this->str[i];
    new[j] = '\0';
    if (strlen(str->str) > strlen(this->str)) {
        free(new);
        return -1;
    }
    test = strstr(new, str->str);
    if (test == NULL) {
        free(new);
        return -1;
    }
    res = strlen(this->str) - strlen(test);
    free(new);
    return res;
}

int find_c (const string_t *this, const char *str, size_t pos)
{
    char *new = malloc(sizeof(char) * (strlen(this->str) + 1));
    char *test;
    int res = 0;
    int j = 0;

    for (int i = pos; this->str[i]; i++, j++)
        new[j] = this->str[i];
    new[j] = '\0';
    if (strlen(str) > strlen(this->str)) {
        free(new);
        return -1;
    }
    test = strstr(new, str);
    if (test == NULL) {
        free(new);
        return -1;
    }
    res = strlen(this->str) - strlen(test);
    free(new);
    return res;
}
