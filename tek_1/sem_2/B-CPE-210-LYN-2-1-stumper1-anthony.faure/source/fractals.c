/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper1-anthony.faure
** File description:
** fractals
*/

#include "../include/my.h"

void step1(char **fst, char **scd, int flag, int nb)
{
    for (int a = 0; fst[a + 1] != NULL; a++) {
        for (int i = 0; i != nb; i++) {
            my_putstr(fst[a], 1);
        }
        for (int i = 0; i != nb; i++) {
            my_putstr(scd[a], 1);
        }
        for (int i = 0; i != nb; i++) {
            my_putstr(fst[a], 1);
        }
        my_putchar('\n', 1);
    }
    return;
}

void step2(char **fst, char **scd, int res, int nb)
{
    for (int a = 0; fst[a + 1] != NULL; a++) {
        for (int i = 0; i != nb * nb; i++) {
            my_putstr(fst[a], 1);
        }
        my_putchar('\n', 1);
    }
    for (int a = 0; fst[a + 1] != NULL; a++) {
        for (int i = 0, j = 0; j != nb * nb; j++) {
            res = (i + nb) % nb;
            ((res % 2 == 0) ? (i += 1) : (i -= 2));
            ((res % 2 == 0) ? my_putstr(fst[a], 1) : my_putstr(scd[a], 1));
        }
        my_putchar('\n', 1);
    }
    for (int a = 0; fst[a + 1] != NULL; a++) {
        for (int i = 0; i != nb * nb; i++) {
            my_putstr(fst[a], 1);
        }
        my_putchar('\n', 1);
    }
}

void step3(char **fst, char **scd, int flag, int nb)
{
    for (int a = 0; fst[a + 1] != NULL; a++) {
        for (int i = 0; i != nb; i++) {
            ((i % 2 == 0) ? my_putstr(fst[a], 1) : my_putstr(scd[a], 1));
        }
        for (int i = 0; i != nb; i++) {
            my_putstr(scd[a], 1);
        }
        for (int i = 0; i != nb; i++) {
            ((i % 2 == 0) ? my_putstr(fst[a], 1) : my_putstr(scd[a], 1));
        }
        my_putchar('\n', 1);
    }
    return;
}

int freee(char **one, char **two)
{
    int a = 0;

    for (a = 0; one[a + 1] != NULL; a++)
        free(one[a]);
    free(one[a]);
    free(one);
    for (a = 0; two[a + 1] != NULL; a++)
        free(two[a]);
    free(two[a]);
    free(two);
    return 0;
}

int fractals(char **fst, char **scd, int flag, int nb)
{
    int res = 0;

    if (flag == 1) {
        return freee(fst, scd);
    } else if (flag % 2 == 0) {
        step1(fst, scd, flag, nb);
        step2(fst, scd, res, nb);
    } else {
        step2(fst, scd, res, nb);
        step1(fst, scd, flag, nb);
        step3(fst, scd, flag, nb);
    }
    return fractals(fst, scd, --flag, nb);
}
