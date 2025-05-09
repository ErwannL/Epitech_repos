/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strcmp
*/

#include "../include/c_test.h"

void print_test_strcmp(char *src, size_t (*my_strcmp)(const char *,
    const char *))
{
    printf ("\nstrcmp = %i   | my_strcmp = %i\n", strcmp(src, "Hello World"),
        my_strcmp(src, "Hello World"));
    printf ("strcmp = %i | my_strcmp = %i\n", strcmp(src, "Hello Worl"),
        my_strcmp(src, "Hello Worl"));
    printf ("strcmp = %i | my_strcmp = %i\n", strcmp(src, "Hello World nop"),
        my_strcmp(src, "Hello World nop"));
}

int test_function_strcmp(char *src, size_t (*my_strcmp)(const char *,
    const char *))
{
    return (strcmp(src, "Hello World") == my_strcmp(src, "Hello World")
        && strcmp(src, "Hello Worl") == my_strcmp(src, "Hello Worl")
        && strcmp(src, "Hello World nop"), my_strcmp(src, "Hello World nop")
        ? 0 : 84);
}

int test_strcmp(char *src, void *handle, bool color, bool details)
{
    char *error;
    size_t (*my_strcmp)(const char *, const char *);

    my_strcmp = dlsym (handle, "strcmp");
    error = dlerror();
    if (!my_strcmp) {
        (color == true) ? red() : 0;
        printf("\nErreur dans strcmp %s\n", error);
        reset();
        return 84;
    }
    (color == true) ? green() : 0;
    if (details == true)
        print_test_strcmp(src, my_strcmp);
    else
        (test_function_strcmp(src, my_strcmp) == 0) ? printf("\nstrcmp : OK\n")
        : (((color == true) ? red() : 0),
        printf("\nstrcmp :/!\\ BAD /!\\\n"));
    reset();
    return 0;
}
