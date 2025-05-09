/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD05-erwann.laplante
** File description:
** clear
*/

#include "string.h"

void clear(string_t *this)
{
    if (this == NULL)
        return;
    if (this->str != NULL)
        free(this->str);
    this->str = strdup("");
    return;
}
