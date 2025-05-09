/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** check_twins
*/

#include "lemin.h"

int check_twins(List *room_list, char *new_name)
{
    Element *current_list = room_list->first;

    if (room_list == NULL)
        return(EXIT_FAILURE);
    while (current_list != NULL) {
        if (current_list->name == NULL)
            break;
        if (str_cmp(new_name, current_list->name) == 0)
           return (84);
        current_list = current_list->next;
    }
    return (0);
}
