/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** test
*/

#include "lemin.h"

dij_t *dijkstra_second(dij_t *diji, int c, char *now_next, int k)
{
    while (c != 0) {
        for (; now_next[k] != ' ' && now_next[k] != '\0' && now_next[k]; k++);
        diji->now_name = my_strncat(diji->now_name, " ", 1);
        diji->now_name = my_strncat(diji->now_name, now_next, k);
        for (int p = 0; diji->now_name[p] != ' ' && diji->now_name[p] != '\0'
        && diji->now_name[p]; diji->now_name++);
        diji->now_name++;
        now_next++;
        for (int j = 0; j != k; j++, now_next++);
        for (int a = diji->stop; a != diji->nbr_node; a++) {
            diji->path[a] = my_strcat(diji->path[a], " ");
            diji->path[a] = my_strcat(diji->path[a], diji->now_name);
        }
        diji = dijkstra(diji);
        diji = rm_node(diji);
        c--;
    }
    diji = rm_node(diji);
    return diji;
}

dij_t *dijkstra(dij_t *diji)
{
    int k = 0;
    char *now_next;
    int c = 0;

    if (find_end(diji) == 84)
        return diji;
    for (int i = 0; i != diji->nbr_node; i++) {
        now_next = no_next(diji, now_next, i);
        if (now_next == NULL)
            return diji;
    }
    k = 0;
    for (int count = 0; now_next[count] != '\0'; count++)
        (now_next[count] == ' ') ? c++ : 0;
    c++;
    return dijkstra_second(diji, c, now_next, k);
}

dij_t *get_room(List *room_list, dij_t *diji, List *path)
{
    Element *current_list = room_list->first;
    Element *current_path = path->first;

    for (int i = 0; i != diji->nbr_node; i++) {
        diji->nodes[i] = create_node(current_list->name);
        current_list = current_list->next;
    }
    while (current_path->next != NULL) {
        for (int i = 0; i != diji->nbr_node; i++) {
            diji->nodes[i] = (my_strcmp(diji->nodes[i].name
            , get_start_path(current_path->name)) == 0) ?
            modif_node(diji->nodes[i], get_end_path(current_path->name)) :
            diji->nodes[i];
        }
        current_path = current_path->next;
    }
    return diji;
}

dij_t *init_struct(dij_t *diji, List *comp_room, List *room_list, List *path)
{
    diji->now_name = clean_start(get_start(comp_room));
    diji->nbr_node = get_nbroom(room_list) + 1;
    diji->nodes = malloc(sizeof(node_t) * (diji->nbr_node + 1));
    diji->end = clean_start(get_end(comp_room));
    diji->path = malloc(sizeof(char *) * (diji->nbr_node + 1));
    diji->stop = 0;
    for (int a = 0; a != diji->nbr_node; diji->path[a] = "", a++);
    diji = get_room(room_list, diji, path);
    return diji;
}

path_t *main_di(path_t *r_path, List *room_list, List *path, List *comp_room)
{
    dij_t *diji = malloc(sizeof(dij_t));
    int num = 0;
    diji = init_struct(diji, comp_room, room_list, path);
    diji = dijkstra(diji);
    for (int a = 0; a != diji->nbr_node; a++) {
        diji->path[a] = my_revstr(diji->path[a]);
        (diji->path[a][0] == '|') ? num++ : 0;
        diji->path[a] = my_revstr(diji->path[a]);
    }
    diji->nbr_node = num;
    for (int a = 0; a != diji->nbr_node; diji->path[a]++, a++);
    for (int i = 0; i != diji->nbr_node; i++) {
        diji->path[i] = my_revstr(diji->path[i]);
        diji->path[i]++;
        diji->path[i]++;
    }
    r_path->nbr_node = diji->nbr_node;
    r_path->path = diji->path;
    return r_path;
}
