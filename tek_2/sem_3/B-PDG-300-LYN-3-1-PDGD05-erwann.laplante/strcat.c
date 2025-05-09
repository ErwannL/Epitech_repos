/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD05-erwann.laplante
** File description:
** strcat
*/

#include "string.h"

char *my_strcat(char *dest, const char *src)
{
    char *dest2;
    int len_1 = strlen(dest);
    int len_2 = strlen(src);
    int i = 0;

    dest2 = malloc(sizeof(char) * (len_1 + len_2 + 1));
    dest2 = strcpy(dest2, dest);
    dest2[strlen(dest2)] = '\0';
    while (i <= len_2) {
        dest2[len_1 + i] = src[i];
        i++;
    }
    free(dest);
    return (dest2);
}
