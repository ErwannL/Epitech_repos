/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD05-erwann.laplante
** File description:
** lenght
*/

#include "string.h"

int length (const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return -1;
    return strlen(this->str);
}
