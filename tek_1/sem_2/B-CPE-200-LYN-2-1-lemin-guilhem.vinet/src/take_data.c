/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** take_date
*/

#include "lemin.h"

int get_nbroom(List *room)
{
    Element *current_list = room->first;
    int nb = -1;

    if (room == NULL) {
        return(EXIT_FAILURE);
    }
    while (current_list != NULL) {
        if (current_list->name == NULL)
            return(nb);
        nb ++;
        current_list = current_list->next;
    }
    return (nb);
}
