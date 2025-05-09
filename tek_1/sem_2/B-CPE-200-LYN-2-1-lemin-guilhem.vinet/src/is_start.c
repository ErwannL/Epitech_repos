/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** is_start
*/

#include "lemin.h"

int test_end(char **buf, int i, int len, int end)
{
    if (i + 1 == len) {
        return (84);
    }
    if (check_room(buf[i + 1]) == 84) {
        return (84);
    }
    end = 1;
    return (end);
}

int is_start(char **buf, List *room)
{
    int start = 0;
    int end = 0;
    int len = len_tab(buf);

    for (int i = 1; i != len; i ++) {
        if (str_cmp(buf[i], "##start") == 1 && check_room(buf[i]) == 84 &&\
        str_cmp(buf[i], "##end") == 1 && is_path(buf[i]) == 84 &&
        buf[i][0] != '#') {
            return(84);
        } else
            start = 1;
        if (str_cmp(buf[i], "##end") == 0) {
            end = test_end(buf, i, len, end);
        }
    }
    return (((start != 1) || (end != 1)) ? 84 : 0);
}
