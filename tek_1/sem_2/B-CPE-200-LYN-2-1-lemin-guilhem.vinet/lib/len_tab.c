/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** len_tab
*/

#include "lemin.h"

int len_array(char **array)
{
    int len = 0;

    while (array[len] != NULL)
        len ++;
    return (len);
}

int len_tab(char **buf)
{
    int len = 0;

    while (buf[len][0] != '\0')
        len ++;
    return (len);
}
