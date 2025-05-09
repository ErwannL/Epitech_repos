/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** test_name
*/

#include "lemin.h"

int do_strcmp(char *name_list, char *name)
{
    if (my_strcmp(name_list, name) == 0)
        return (1);
    return (0);
}

int compare_name(char *name, List *room)
{
    Element *current_list = room->first;
    int check = 0;
    if (room == NULL) {
        return(EXIT_FAILURE);
    }
    while (current_list != NULL) {
        if (current_list->name != NULL || check == 1) {
            check = do_strcmp(current_list->name, name);
        }
        if (check == 1)
            return (0);
        current_list = current_list->next;
    }
    if (check != 1)
        return (84);
    return (0);
}

int compare_checkpoint(char *name, List *room)
{
    Element *current_list = room->first;

    if (room == NULL) {
        return(EXIT_FAILURE);
    }
    while (current_list != NULL) {
        if (str_cmp(name, current_list->name) == 0 && current_list->start == 1)
            return (1);
        if (str_cmp(name, current_list->name) == 0  && current_list->end == 2)
            return (2);
        current_list = current_list->next;
    }
    return (0);
}

int test_double(char **array)
{
    if (my_strcmp(array[0], array[1]) == 0)
        return (84);
    return (0);
}

int test_name(char **buf, List *room)
{
    char **array = NULL;
    int error_double = 0;
    int error = 0;
    int error_sc = 0;

    for (int i = 0; buf[i] != NULL; i ++) {
        if (buf[i] == NULL)
            return(84);
        if (is_path(buf[i]) != 84) {
            array = word_array(buf[i], '-');
            error_double = test_double(array);
            error = compare_name(array[0], room);
            error_sc = compare_name(array[1], room);
            free(array);
        }
        if (error == 84 || error_double == 84 || error_sc == 84)
            return (84);
    }
    return(0);
}
