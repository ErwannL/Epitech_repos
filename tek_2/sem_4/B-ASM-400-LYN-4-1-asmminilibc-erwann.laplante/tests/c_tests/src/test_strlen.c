/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strlen
*/

#include "../include/c_test.h"

int test_strlen(char *src, void *handle, bool color, bool details)
{
    char *error;
    size_t (*my_strlen)(const char *);

    my_strlen = dlsym (handle, "strlen");
    error = dlerror();
    if (!my_strlen) {
        (color == true) ? red() : 0;
        printf("\nErreur dans strlen %s\n", error);
        reset();
        return 84;
    }
    (color == true) ? green() : 0;
    if (details == true)
        printf ("\nstrlen = %i | my_strlen = %i\n", strlen(src),
            my_strlen(src));
    else
        (strlen(src) == my_strlen(src)) ? printf("\nstrlen : OK\n") :
        (((color == true) ? red() : 0), printf("\nstrlen :/!\\ BAD /!\\\n"));
    reset();
    return 0;
}
