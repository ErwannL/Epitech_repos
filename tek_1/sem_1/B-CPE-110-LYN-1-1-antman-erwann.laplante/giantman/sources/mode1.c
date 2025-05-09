/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
** File description:
** mode1
*/

#include "../include/my.h"

char *have_cryped(char *src)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *dest;

    for (; src[k] != '\n'; k++);
    k++;
    for (j = k; src[j] != '\0'; j++);
    dest = malloc(sizeof(char) * ((j - k) + 1));
    i = k;
    while (src[i] != '\0') {
        dest[(i - k)] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}

char *cpy_str(char *src)
{
    int i = 0;
    int j = 0;
    char *dest;

    for (; src[j] != '\n'; j++);
    dest = malloc(sizeof(char) * (j + 1));
    while (src[i] != '\n') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}

variable_t mode_1(variable_t var)
{
    char *str = cpy_str(var.buffer);
    char *crypted = have_cryped(var.buffer);

    binary_tree(str, crypted);
    return var;
}
