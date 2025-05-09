/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_memcpy
*/

#include "../include/c_test.h"

void print_test_memcpy(char *src, void *(*my_memcpy)(void *, const void *,
    size_t))
{
    char *test = strdup("");
    char *my_test = strdup("");

    memcpy(test, src, sizeof(src));
    my_memcpy(my_test, src, sizeof(src));
    printf ("\nmemcpy = %s | my_memcpy = %s\n", test, my_test);
}

int test_function_memcpy(char *src, void *(*my_memcpy)(void *, const void *,
    size_t))
{
    char *test = strdup("");
    char *my_test = strdup("");

    memcpy(test, src, sizeof(src));
    my_memcpy(my_test, src, sizeof(src));
    return (strcmp(test, my_test) == 0 ? 0 : 84);
}

int test_memcpy(char *src, void *handle, bool color, bool details)
{
    char *error;
    void *(*my_memcpy)(void *, const void *, size_t);

    my_memcpy = dlsym (handle, "memcpy");
    error = dlerror();
    if (!my_memcpy) {
        (color == true) ? red() : 0;
        printf("\nErreur dans memcpy %s\n", error);
        reset();
        return 84;
    }
    (color == true) ? green() : 0;
    if (details == true)
        print_test_memcpy(src, my_memcpy);
    else
        (test_function_memcpy(src, my_memcpy) == 0) ? printf("\nmemcpy : OK\n")
        : (((color == true) ? red() : 0),
        printf("\nmemcpy :/!\\ BAD /!\\\n"));
    reset();
    return 0;
}
