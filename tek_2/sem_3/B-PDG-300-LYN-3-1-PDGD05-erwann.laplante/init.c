/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD05-erwann.laplante
** File description:
** init
*/

#include "string.h"

void string_init(string_t *this, const char *s)
{
    if (this == NULL)
        return;
    this->str = strdup(s);
    this->assign_c = assign_c;
    this->assign_s = assign_s;
    this->append_c = append_c;
    this->append_s = append_s;
    this->at = at;
    this->clear = clear;
    this->length = length;
    this->compare_c = compare_c;
    this->compare_s = compare_s;
    this->copy = copy;
    this->c_str = c_str;
    this->empty = empty;
    this->find_c = find_c;
    this->find_s = find_s;
}
