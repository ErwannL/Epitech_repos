/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD05-erwann.laplante
** File description:
** empty
*/

#include "string.h"

int empty (const string_t *this)
{
    if (strcmp(this->str, "") == 0)
        return 1;
    return 0;
}
