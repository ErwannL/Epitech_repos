/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-lemin-guilhem.vinet
** File description:
** cut_com
*/

#include "lemin.h"

char *cut_com(char *buf)
{
    int i = 0;
    char *str;
    int copy = 0;

    while (buf[i] != '\0') {
        if (buf[i] == '#') {
            copy = 1;
            str = malloc(sizeof(char) * i);
            break;
        }
        i ++;
    }
    if (buf[i] == ' ')
        i --;
    if (copy == 1)
        for (int j = 0; j < i; j ++)
            str[j] = buf[j];
    else
        return (buf);
    return(str);
}