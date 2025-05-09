/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** dij_util_bis
*/

#include "lemin.h"

char *clean_start(char *start)
{
    start = my_revstr(start);
    for (; start[0] != ' '; start++);
    start++;
    for (; start[0] != ' '; start++);
    start++;
    start = my_revstr(start);
    return(start);
}

char *get_start(List *comp_room)
{
    Element *current_list = comp_room->first;

    if (comp_room == NULL) {
        return(NULL);
    }
    while (current_list != NULL) {
        if (current_list->name == NULL)
            return (NULL);
        if (current_list->start == 1) {
            return current_list->name;
        }
        current_list = current_list->next;
    }
    return (NULL);
}

char *get_end(List *comp_room)
{
    Element *current_list = comp_room->first;

    if (comp_room == NULL) {
        return(NULL);
    }
    while (current_list != NULL) {
        if (current_list->name == NULL)
            return (NULL);
        if (current_list->end == 2) {
            return current_list->name;
        }
        current_list = current_list->next;
    }
    return (NULL);
}

char *get_start_path(char *path)
{
    char *start;
    int i = 0;

    for (; path[i] != '-'; i++);
    start = malloc(sizeof(char) * (i + 1));
    start[i] = '\0';
    for (int j = 0; j != i; j++) {
        start[j] = path[0];
        path++;
    }
    return start;
}

char *get_end_path(char *path)
{
    char *end;
    int i = 0;

    path = my_revstr(path);
    for (; path[i] != '-'; i++);
    end = malloc(sizeof(char) * (i + 1));
    end[i] = '\0';
    for (int j = 0; j != i; j++) {
        end[j] = path[0];
        path++;
    }
    return my_revstr(end);
}
