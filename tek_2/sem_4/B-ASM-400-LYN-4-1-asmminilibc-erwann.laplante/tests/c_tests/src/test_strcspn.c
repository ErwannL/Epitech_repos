/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strcspn
*/

#include "../include/c_test.h"

void print_test_strcspn(char *src, size_t (*my_strcspn)(const char *,
    const char *))
{
    printf ("\nstrcspn = %i | my_strcspn = %i\n", strcspn(src, "z"),
        my_strcspn(src, "z"));
    printf ("strcspn = %i  | my_strcspn = %i\n", strcspn(src, "e"),
        my_strcspn(src, "e"));
    printf ("strcspn = %i  | my_strcspn = %i\n", strcspn(src, "ez"),
        my_strcspn(src, "ez"));
    printf ("strcspn = %i  | my_strcspn = %i\n", strcspn(src, "ze"),
        my_strcspn(src, "ze"));
    printf ("strcspn = %i  | my_strcspn = %i\n", strcspn(src, "ll"),
        my_strcspn(src, "ll"));
    printf ("strcspn = %i  | my_strcspn = %i\n", strcspn(src, "ol"),
        my_strcspn(src, "ol"));
    printf ("strcspn = %i  | my_strcspn = %i\n", strcspn(src, "lo"),
        my_strcspn(src, "lo"));
    printf ("strcspn = %i  | my_strcspn = %i\n", strcspn(src, "He"),
        my_strcspn(src, "He"));
    printf ("strcspn = %i | my_strcspn = %i\n", strcspn(src, "d"),
        my_strcspn(src, "d"));
}

int test_function_strcspn(char *src, size_t (*my_strcspn)(const char *,
    const char *))
{
    return (strcspn(src, "z") == my_strcspn(src, "z")
        && strcspn(src,"e") == my_strcspn(src, "e")
        && strcspn(src, "ez") == my_strcspn(src, "ez")
        && strcspn(src, "ze") == my_strcspn(src, "ze")
        && strcspn(src, "ll") == my_strcspn(src, "ll")
        && strcspn(src, "ol") == my_strcspn(src, "ol")
        && strcspn(src, "lo") == my_strcspn(src, "lo")
        && strcspn(src, "He") == my_strcspn(src, "He")
        && strcspn(src, "d") == my_strcspn(src, "d") ? 0 : 84);
}

int test_strcspn(char *src, void *handle, bool color, bool details)
{
    char *error;
    size_t (*my_strcspn)(const char *, const char *);

    my_strcspn = dlsym (handle, "strcspn");
    error = dlerror();
    if (!my_strcspn) {
        (color == true) ? red() : 0;
        printf("\nErreur dans strcspn %s\n", error);
        reset();
        return 84;
    }
    (color == true) ? green() : 0;
    if (details == true)
        print_test_strcspn(src, my_strcspn);
    else
        (test_function_strcspn(src, my_strcspn) == 0) ?
        printf("\nstrcspn : OK\n") : (((color == true) ? red() : 0),
        printf("\nstrcspn :/!\\ BAD /!\\\n"));
    reset();
    return 0;
}
