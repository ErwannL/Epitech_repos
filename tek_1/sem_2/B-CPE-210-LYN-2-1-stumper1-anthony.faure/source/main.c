/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper1-anthony.faure
** File description:
** main
*/

#include "../include/my.h"

int case_two(char **fst, int *nb_ad, char **scd)
{
    for (int a = 0; fst[a + 1] != NULL; a++) {
        for (int i = 0; i != nb_ad[0]; i++) {
            my_putstr(fst[a], 1);
        }
        my_putchar('\n', 1);
    }
    for (int a = 0; fst[a + 1] != NULL; a++) {
        for (int i = 0; i != nb_ad[0] / 2; i++) {
            my_putstr(fst[a], 1);
            my_putstr(scd[a], 1);
        }
        my_putchar('\n', 1);
    }
    return 0;
}

int three(char **argv, char **scd, int *nb_ad, char **fst)
{
    for (int i = 0, j = 0, a = 0; argv[3][i] != '\0'; i++, a++) {
        if (argv[3][i] == '@') {
            j += 1;
            a = -1;
        } else {
            scd[j][a] = argv[3][i];
        }
    }
    if (nb_ad[0] == 2) {
        case_two(fst, nb_ad, scd);
        return 0;
    }
    return fractals(fst, scd, nb_ad[0], nb_ad[0]);
}

int second(char **fst, char **scd, char **argv, int *nb_ad)
{
    int lin = 0;

    lin += nb_ad[1] - 1;
    for (int i = 0; i != nb_ad[1]; i++) {
        fst[i] = malloc(sizeof(char) * lin);
        scd[i] = malloc(sizeof(char) * lin);
    }
    fst[nb_ad[1]] = NULL;
    scd[nb_ad[1]] = NULL;
    for (int i = 0, j = 0, a = 0; argv[2][i] != '\0'; i++, a++) {
        if (argv[2][i] == '@') {
            j += 1;
            a = -1;
        } else {
            fst[j][a] = argv[2][i];
        }
    }
    return three(argv, scd, nb_ad, fst);
}

int case_one(char **argv)
{
    for (int i = 0; argv[2][i] != '\0'; i++) {
        if (argv[2][i] == '@') {
            i++;
            my_putchar('\n', 1);
        }
        my_putchar(argv[2][i], 1);
    }
    my_putchar('\n', 1);
    return 0;
}

int main(int argc, char **argv)
{
    int nb;
    int *nb_ad = malloc(sizeof(int) * 3);
    char **fst;
    char **scd;

    nb_ad[1] = 2;
    if (argc != 4 || check_errors(argv) == 84)
        return error_arg();
    nb_ad[0] = my_atoi(argv[1]);
    if (nb_ad[0] == 0) {
        my_putchar(argv[2][0], 1);
        my_putchar('\n', 1);
        return 0;
    } else if (nb_ad[0] == 1)
        return case_one(argv);
    for (int i = 0; argv[2][i] != '\0'; i += 1)
        (argv[2][i] == '@') ? nb_ad[1] += 1 : 0;
    fst = malloc(sizeof(char *) * nb_ad[1]);
    scd = malloc(sizeof(char *) * nb_ad[1]);
    return second(fst, scd, argv, nb_ad);
}
