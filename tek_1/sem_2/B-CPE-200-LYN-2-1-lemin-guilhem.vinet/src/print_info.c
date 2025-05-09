/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** print_info
*/

#include "lemin.h"

void print_begin(char **buf)
{
    my_putstr("#number_of_ants\n");
    my_putstr(buf[0]);
    my_putchar('\n');
    my_putstr("#rooms\n");
}

void avoid_comment(char *str)
{
    int i = 0;

    while (str[i] != '\0' && str[i + 1] != '#') {
        my_putchar(str[i]);
        i = i + 1;
    }
}

void print_start(char *room, List *comp_room)
{
    if (compare_checkpoint(room, comp_room) == 1) {
        my_putstr("##start\n");
    }
    if (compare_checkpoint(room, comp_room) == 2)
        my_putstr("##end\n");
}

void print_info(char **buf, List *comp_room, List *path)
{
    char **array_room = chain_to_array(comp_room);
    char **array_path = chain_to_array(path);

    print_begin(buf);
    for (int i = len_array(array_room); i >= 0; i --) {
        if (array_room[i] != NULL) {
            print_start(array_room[i], comp_room);
            avoid_comment(array_room[i]);
            my_putchar('\n');
        }
    }
    my_putstr("#tunnels\n");
    for (int i = len_array(array_path); i >= 0; i --) {
        if (array_path[i] != NULL) {
            my_putstr(array_path[i]);
            my_putchar('\n');
        }
    }
    my_putstr("#moves\n");
}
