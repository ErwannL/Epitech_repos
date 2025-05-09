/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** clean_str
*/

#include "lemin.h"

int test_function(char c)
{
    if (c != ' ' && c != '\t')
        return 0;
    return 1;
}

char *clean_string(char *str)
{
    int state = 0;
    int a = 0;

    for (; (test_function(str[0]) == 1) && (str[1] != '\0'); str++);
    for (int i = 0; str[i] != '\0'; i++) {
        if (test_function(str[i]) == 0) {
            str[a] = str[i];
            a++;
            state = 1;
        } else if ((test_function(str[i]) == 1) && state == 1
        && str[i + 1] != '\0' && test_function(str[i + 1]) == 0) {
            str[a] = ' ';
            a++;
            state = 0;
        }
    }
    str = my_revstr(str);
    for (; (test_function(str[0]) == 1) && (str[1] != '\0'); str++);
    str = my_revstr(str);
    return str;
}
