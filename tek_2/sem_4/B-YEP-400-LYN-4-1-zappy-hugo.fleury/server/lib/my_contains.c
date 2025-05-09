/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-thomas.brossard
** File description:
** my_contains
*/

#include "../include/my_teams.h"

int my_contains(char const *str, char *regex)
{
    int index = 0;

    for (int r = 0; str[index]; index++) {
        r = (regex[r] && str[index] == regex[r]) ? r + 1 : 0;
        if (!regex[r])
            return (index);
    }
    return (0);
}

int my_contains_b(char const *str, char *regex)
{
    int index = 0;

    for (int r = 0, k = 0; str[index]; index++) {
        if (regex[r] && str[index] == regex[r]) {
            r++;
            (r == 1) ? k = index : 0;
        }
        if (!regex[r])
            return (k);
    }
    return (0);
}
