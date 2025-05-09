/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strncasecmp
*/

#include "../include/c_test.h"

void print_test_strncasecmp(char *src, size_t (*my_strncasecmp)(const char *,
    const char *, size_t))
{
    printf ("\nstrncasecmp = %i   | my_strncasecmp = %i\n", strncasecmp(src,
        "Hello World", 11), my_strncasecmp(src, "Hello World", 11));
    printf ("strncasecmp = %i   | my_strncasecmp = %i\n", strncasecmp(src,
        "Hello World", 5), my_strncasecmp(src, "Hello World", 5));
    printf ("strncasecmp = %i | my_strncasecmp = %i\n", strncasecmp(src,
        "Hello Worl", 11), my_strncasecmp(src, "Hello Worl", 11));
    printf ("strncasecmp = %i   | my_strncasecmp = %i\n", strncasecmp(src,
        "Hello Worl", 5), my_strncasecmp(src, "Hello Worl", 5));
    printf ("strncasecmp = %i   | my_strncasecmp = %i\n", strncasecmp(src,
        "Hello World nop", 11), my_strncasecmp(src, "Hello World nop", 11));
    printf ("strncasecmp = %i   | my_strncasecmp = %i\n", strncasecmp(src,
        "Hello World nop", 5), my_strncasecmp(src, "Hello World nop", 5));
}

int test_function_strncasecmp(char *src, size_t (*my_strncasecmp)(const char *,
    const char *, size_t))
{
    return (strncasecmp(src, "Hello World", 11) == my_strncasecmp(src,
        "Hello World", 11)
        && strncasecmp(src, "Hello world", 5) == my_strncasecmp(src,
            "Hello world", 5)
        && strncasecmp(src, "Hello Worl", 11) == my_strncasecmp(src,
            "Hello Worl", 11)
        && strncasecmp(src, "Hello worl", 5) == my_strncasecmp(src,
            "Hello worl", 5)
        && strncasecmp(src, "Hello World nop", 11) == my_strncasecmp(src,
            "Hello World nop", 11)
        && strncasecmp(src, "Hello world nop", 5) == my_strncasecmp(src,
            "Hello world nop", 5) ? 0 : 84);
}

int test_strncasecmp(char *src, void *handle, bool color, bool details)
{
    char *error;
    size_t (*my_strncasecmp)(const char *, const char *, size_t);

    my_strncasecmp = dlsym (handle, "strncasecmp");
    error = dlerror();
    if (!my_strncasecmp) {
        (color == true) ? red() : 0;
        printf ("\nErreur dans strncasecmp %s\n", error);
        reset();
        return 84;
    }
    (color == true) ? green() : 0;
    if (details == true)
        print_test_strncasecmp(src, my_strncasecmp);
    else
        (test_function_strncasecmp(src, my_strncasecmp) == 0) ?
        printf("\nstrncasecmp : OK\n") : (((color == true) ? red() : 0),
        printf("\nstrncasecmp :/!\\ BAD /!\\\n"));
    reset();
    return 0;
}
