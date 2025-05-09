/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** cut_name
*/

#include "lemin.h"

char *cut_name(char *name)
{
    int i = 0;
    char *name_cut;

    while (name[i] != ' ')
        i ++;
    name_cut = malloc(sizeof(char) * i);

    for (int j = 0; j < i; j ++)
        name_cut[j] = name[j];
    name_cut[i] = '\0';
    return (name_cut);
}
