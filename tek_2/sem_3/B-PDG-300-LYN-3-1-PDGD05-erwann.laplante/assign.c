/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD05-erwann.laplante
** File description:
** assign
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    if (this == NULL)
        return;
    if (this->str != NULL)
        free(this->str);
    this->str = strdup(str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (this == NULL)
        return;
    if (this->str != NULL)
        free(this->str);
    this->str = strdup(s);
}
