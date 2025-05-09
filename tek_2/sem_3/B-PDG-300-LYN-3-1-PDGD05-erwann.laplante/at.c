/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD05-erwann.laplante
** File description:
** at
*/

#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (this == NULL || this->str == NULL || (int)pos > strlen(this->str))
        return -1;
    return this->str[pos];
}
