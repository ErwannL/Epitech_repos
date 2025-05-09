/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strcasecmp
*/

#include "../include/c_test.h"

void print_test_strcasecmp(char *src, size_t (*my_strcasecmp)(const char *,
    const char *))
{
    printf ("\nstrcasecmp = %i   | my_strcasecmp = %i\n", strcasecmp(src,
        "Hello World"), my_strcasecmp(src, "Hello World"));
    printf ("strcasecmp = %i   | my_strcasecmp = %i\n", strcasecmp(src,
        "Hello world"), my_strcasecmp(src, "Hello world"));
    printf ("strcasecmp = %i   | my_strcasecmp = %i\n", strcasecmp(src,
        "HEllo World"), my_strcasecmp(src, "HEllo World"));
    printf ("strcasecmp = %i | my_strcasecmp = %i\n", strcasecmp(src,
        "Hello Worl"), my_strcasecmp(src, "Hello Worl"));
    printf ("strcasecmp = %i | my_strcasecmp = %i\n", strcasecmp(src,
        "Hello worl"), my_strcasecmp(src, "Hello worl"));
    printf ("strcasecmp = %i | my_strcasecmp = %i\n", strcasecmp(src,
        "HEllo Worl"), my_strcasecmp(src, "HEllo Worl"));
    printf ("strcasecmp = %i | my_strcasecmp = %i\n", strcasecmp(src,
        "Hello World nop"), my_strcasecmp(src, "Hello World nop"));
    printf ("strcasecmp = %i | my_strcasecmp = %i\n", strcasecmp(src,
        "Hello world nop"), my_strcasecmp(src, "Hello world nop"));
    printf ("strcasecmp = %i | my_strcasecmp = %i\n", strcasecmp(src,
        "HEllo World nop"), my_strcasecmp(src, "HEllo World nop"));
}

int test_function_strcasecmp(char *src, size_t (*my_strcasecmp)(const char *,
    const char *))
{
    return (strcasecmp(src, "Hello World") == my_strcasecmp(src, "Hello World")
        && strcasecmp(src, "Hello world") == my_strcasecmp(src, "Hello world")
        && strcasecmp(src, "HEllo World") == my_strcasecmp(src, "HEllo World")
        && strcasecmp(src, "Hello Worl") == my_strcasecmp(src, "Hello Worl")
        && strcasecmp(src, "Hello worl") == my_strcasecmp(src, "Hello worl")
        && strcasecmp(src, "HEllo Worl") == my_strcasecmp(src, "HEllo Worl")
        && strcasecmp(src, "Hello World nop") == my_strcasecmp(src,
            "Hello World nop")
        && strcasecmp(src, "Hello world nop") == my_strcasecmp(src,
            "Hello world nop")
        && strcasecmp(src, "HEllo World nop") == my_strcasecmp(src,
            "HEllo World nop")
        ? 0 : 84);
}

int test_strcasecmp(char *src, void *handle, bool color, bool details)
{
    char *error;
    size_t (*my_strcasecmp)(const char *, const char *);

    my_strcasecmp = dlsym (handle, "strcasecmp");
    error = dlerror();
    if (!my_strcasecmp) {
        (color == true) ? red() : 0;
        printf ("\nErreur dans strcasecmp %s\n", error);
        reset();
        return 84;
    }
    (color == true) ? green() : 0;
    if (details == true)
        print_test_strcasecmp(src, my_strcasecmp);
    else
        (test_function_strcasecmp(src, my_strcasecmp) == 0) ?
        printf("\nstrcasecmp : OK\n") : (((color == true) ? red() : 0),
        printf("\nstrcasecmp :/!\\ BAD /!\\\n"));
    reset();
    return 0;
}
