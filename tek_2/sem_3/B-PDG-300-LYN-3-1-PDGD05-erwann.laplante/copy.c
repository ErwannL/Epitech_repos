/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD05-erwann.laplante
** File description:
** copy
*/

#include "string.h"

size_t copy (const string_t *this, char *s, size_t n, size_t pos)
{
    int j = 0;

    if (strlen(this->str) < pos || n < strlen(this->str) || pos > n)
        return 0;
    for (int i = pos; this->str[i]; i++, j++) {
        s[j] = this->str[i];
    }
    s[j] = '\0';
    return strlen(s) + 1;
}
