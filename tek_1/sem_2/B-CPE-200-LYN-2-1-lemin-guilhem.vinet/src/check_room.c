/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** check_room
*/

#include "lemin.h"

int check_space(char *line, int j)
{
    while (line[j] != ' ') {
        if (line[j] < '0' || line[j] > '9') {
            return (84);
        }
        j ++;
    }
    return (j);
}

int check_end(char *line, int j)
{
    while (line[j] != '\0' && line [j + 1] != '#') {
        if (line[j] < '0' || line[j] > '9') {
            return (84);
        }
        j ++;
    }
    return(0);
}

int check_room(char *line)
{
    int j = 0;

    while (line[j] != ' ') {
        if (line[j] == '\0')
            return (84);
        j ++;
    }
    if (line[j] == ' ')
        j ++;
    j = check_space(line, j);
    if (j == 84)
        return (84);
    if (line[j] == ' ' && line[j + 1] != '\0')
        j ++;
    if (check_end(line, j) == 84)
        return (84);
    return (0);
}
