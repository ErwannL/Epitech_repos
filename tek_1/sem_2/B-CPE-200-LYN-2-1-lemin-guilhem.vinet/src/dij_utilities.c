/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** dij_utilities
*/

#include "lemin.h"

node_t create_node(char *name)
{
    node_t node;

    node.name = name;
    node.next = NULL;
    return node;
}

node_t modif_node(node_t node, char *next)
{
    if (node.next == NULL) {
        node.next = next;
    } else {
        node.next = my_strcat(node.next, " ");
        node.next = my_strcat(node.next, next);
    }
    return node;
}

char *get_next(char *all_next)
{
    int j = 0;
    char *next;

    for (int i = 0; all_next[i] != '\0' && all_next[i] != ' '; i++) {
        j++;
    }
    next = (char *)malloc(sizeof(char) * (j + 1));
    for (int i = 0; all_next[i] != '\0' && all_next[i] != ' '; i++) {
        next[i] = all_next[i];
    }
    return next;
}

char *get_prev(char *str)
{
    char *prev;
    int count = 0;

    str++;
    str = my_revstr(str);
    for (int i = 0; str[i] != ' ' && str[i] != '\0'; str++);
    str++;
    for (int i = 0; str[i] != ' ' && str[i] != '\0'; i++)
        count++;
    prev = (char *)malloc(sizeof(char) * (count + 1));
    prev[count] = '\0';
    for (int i = 0; i != count; i++) {
        prev[i] = str[i];
    }
    return prev;
}

int find_end(dij_t *diji)
{
    if (my_strcmp(diji->now_name, diji->end) == 0) {
        diji->now_name = get_prev(diji->path[diji->stop]);
        diji->path[diji->stop] = my_strcat(diji->path[diji->stop], " |");
        diji->stop++;
        return 84;
    }
    return 0;
}
