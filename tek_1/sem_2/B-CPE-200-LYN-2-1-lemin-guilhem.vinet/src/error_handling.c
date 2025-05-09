/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** error_handling
*/

#include "lemin.h"

int is_path(char *line)
{
    int i = 0;

    while (line[i] != '-') {
        if (line[i] == '\n' || line[i] == '\0')
            return (84);
        i ++;
    }
    if (line[i + 1] == '\n' || line[i + 1] == '\0')
        return (84);
    return (0);
}

int check_insertion(char **buf, int i, List *room_list)
{
    if (is_path(buf[i]) == 84 && check_room(buf[i]) == 84)
        return(84);
    if (check_room(buf[i]) != 84) {
        if (check_twins(room_list, buf[i]) == 84)
            return (84);
        else {
            insertion(room_list, cut_name(buf[i]), 0);
        }
    } else
        return (84);
    return(0);
}

int is_room(char **buf, List *room_list)
{
    int error = 0;

    for (int i = 1; i < len_tab(buf); i ++) {
        if (buf[i] == NULL)
            break;
        if (str_cmp(buf[i], "##") != 0 && str_cmp(buf[i], "#") != 0
        && error == 0 && is_path(buf[i]) != 0)
            error = check_insertion(buf, i, room_list);
        if (error == 84)
            return(84);
    }
    return (error);
}

void fill_list(List *comp_room, List *path, char **buf)
{
    for (int i = 0; buf[i] != NULL; i ++) {
        if (str_cmp(buf[i], "##start") == 0 && buf[i] != NULL) {
            buf[i] = cut_com(buf[i + 1]);
            insertion(comp_room, buf[i + 1], 1);
            i += 2;
        }
        if (str_cmp(buf[i], "##end") == 0 && buf[i] != NULL) {
            buf[i] = cut_com(buf[i + 1]);
            insertion(comp_room, buf[i + 1], 2);
            i += 2;
        }
        if (check_room(buf[i]) != 84 && is_path(buf[i]) == 84) {
            buf[i] = cut_com(buf[i]);
            insertion(comp_room, buf[i], 0);
        }
        if (is_path(buf[i]) != 84 && check_room(buf[i]) == 84) {
            insertion(path, buf[i], 0);
        }
    }
}

int error_handling(char **buf, List *room_list, List *comp_room, List *path)
{
    if (my_getnbr(buf[0], 0) == 0)
        return (84);
    if (is_start(buf, room_list) == 84)
        return (84);
    if (is_room(buf, room_list) == 84)
        return (84);
    if (test_name(buf, room_list) == 84)
        return (84);
    fill_list(comp_room, path, buf);
    print_info(buf, comp_room, path);
    return (0);
}
