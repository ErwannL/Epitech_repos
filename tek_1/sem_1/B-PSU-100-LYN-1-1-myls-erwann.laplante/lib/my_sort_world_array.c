/*
** EPITECH PROJECT, 2021
** B-PSU-100-LYN-1-1-bsmyls-erwann.laplante
** File description:
** my_ls
*/

#include "../includes/my.h"

char **condition2(char **argv, int i, int j)
{
    char *temp;

    if (my_strcmp(argv[i], argv[j]) > 0) {
        temp = argv[i];
        argv[i] = argv[j];
        argv[j] = temp;
    }
    return (argv);
}

void sort_word_array2(int argc, char **argv)
{
    int count = 0;

    for (int i = 1; i < argc - 1; i++) {
        for (int j = i + 1; j < argc; j++)
            condition2(argv, i, j);
    }
    while (count < argc)
        count++;
}

char **condition1(char **argv, int i, int j)
{
    char *temp;

    if (my_strcmp_bis(argv[i], argv[j]) > 0) {
        temp = argv[i];
        argv[i] = argv[j];
        argv[j] = temp;
    }
    return (argv);
}

void sort_word_array1(int argc, char **argv)
{
    int count = 0;

    for (int i = 0; i < argc - 1; i++) {
        for (int j = i + 1; j < argc; j++)
            condition1(argv, i, j);
    }
    while (count < argc) {
        my_putstr(argv[count]);
        if (count + 1 != argc)
            my_putstr("  ");
        count++;
    }
}
