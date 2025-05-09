/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strspn
*/

#include "../include/c_test.h"

void print_test_strspn(char *src, size_t (*my_strspn)(const char *,
    const char *))
{
    printf ("\nstrspn = %i | my_strspn = %i\n", strspn(src, "z"),
        my_strspn(src, "z"));
    printf ("strspn = %i | my_strspn = %i\n", strspn(src, "H"),
        my_strspn(src, "H"));
    printf ("strspn = %i | my_strspn = %i\n", strspn(src, "Hz"),
        my_strspn(src, "Hz"));
    printf ("strspn = %i | my_strspn = %i\n", strspn(src, "ze"),
        my_strspn(src, "ze"));
    printf ("strspn = %i | my_strspn = %i\n", strspn(src, "ll"),
        my_strspn(src, "ll"));
    printf ("strspn = %i | my_strspn = %i\n", strspn(src, "ol"),
        my_strspn(src, "ol"));
    printf ("strspn = %i | my_strspn = %i\n", strspn(src, "lo"),
        my_strspn(src, "lo"));
    printf ("strspn = %i | my_strspn = %i\n", strspn(src, "He"),
        my_strspn(src, "He"));
    printf ("strspn = %i | my_strspn = %i\n", strspn(src, "d"),
        my_strspn(src, "d"));
    printf ("strspn = %i | my_strspn = %i\n", strspn(src, "Hello"),
        my_strspn(src, "Hello"));
}

int test_function_strspn(char *src, size_t (*my_strspn)(const char *,
    const char *))
{
    return (strspn(src, "z") == my_strspn(src, "z")
        && strspn(src,"H") == my_strspn(src, "H")
        && strspn(src, "Hz") == my_strspn(src, "Hz")
        && strspn(src, "ze") == my_strspn(src, "ze")
        && strspn(src, "ll") == my_strspn(src, "ll")
        && strspn(src, "ol") == my_strspn(src, "ol")
        && strspn(src, "lo") == my_strspn(src, "lo")
        && strspn(src, "He") == my_strspn(src, "He")
        && strspn(src, "d") == my_strspn(src, "d")
        && strspn(src, "Hello") == my_strspn(src, "Hello")
        ? 0 : 84);
}

int test_strspn(char *src, void *handle, bool color, bool details)
{
    char *error;
    size_t (*my_strspn)(const char *, const char *);

    my_strspn = dlsym (handle, "strspn");
    error = dlerror();
    if (!my_strspn) {
        (color == true) ? red() : 0;
        printf("\nErreur dans strspn %s\n", error);
        reset();
        return 84;
    }
    (color == true) ? green() : 0;
    if (details == true)
        print_test_strspn(src, my_strspn);
    else
        (test_function_strspn(src, my_strspn) == 0) ?
        printf("\nstrspn : OK\n") : (((color == true) ? red() : 0),
        printf("\nstrspn :/!\\ BAD /!\\\n"));
    reset();
    return 0;
}
