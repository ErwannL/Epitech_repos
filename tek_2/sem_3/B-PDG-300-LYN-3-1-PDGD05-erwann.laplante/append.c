/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD05-erwann.laplante
** File description:
** append
*/

#include "string.h"

void append_s (string_t *this, const string_t *ap)
{
    if (this == NULL)
        return;
    if (this->str == NULL)
        this->str = strdup(ap->str);
    else
        this->str = my_strcat(this->str, ap->str);
}

void append_c (string_t *this, const char *ap)
{
    if (this == NULL)
        return;
    if (this->str == NULL)
        this->str = strdup(ap);
    else
        this->str = my_strcat(this->str, ap);
}
