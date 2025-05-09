/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strncmp
*/

#include "../include/c_test.h"

void print_test_strncmp(char *src, size_t (*my_strncmp)(const char *,
    const char *, size_t))
{
    printf ("\nstrncmp = %i   | my_strncmp = %i\n", strncmp(src, "Hello World",
        20), my_strncmp(src, "Hello World", 20));
    printf ("strncmp = %i   | my_strncmp = %i\n", strncmp(src, "Hello Word",
        9), my_strncmp(src, "Hello Word", 9));
    printf ("strncmp = %i | my_strncmp = %i\n", strncmp(src, "Hello World nop",
        20), my_strncmp(src, "Hello World nop", 20));
    printf ("strncmp = %i   | my_strncmp = %i\n", strncmp(src, "Hello", 0),
        my_strncmp(src, "Hello", 0));
}

int test_function_strncmp(char *src, size_t (*my_strncmp)(const char *,
    const char *, size_t))
{
    return (strncmp(src, "Hello World", 20) == my_strncmp(src, "Hello World",
            20)
        && strncmp(src, "Hello Word", 9) == my_strncmp(src, "Hello Word", 9)
        && strncmp(src, "Hello World nop", 20) == my_strncmp(src,
            "Hello World nop", 20)
        && strncmp(src, "Hello", 0) == my_strncmp(src, "Hello", 0)
        ? 0 : 84);
}

int test_strncmp(char *src, void *handle, bool color, bool details)
{
    char *error;
    size_t (*my_strncmp)(const char *, const char *, size_t);

    my_strncmp = dlsym (handle, "strncmp");
    error = dlerror();
    if (!my_strncmp) {
        (color == true) ? red() : 0;
        printf("\nErreur dans strncmp %s\n", error);
        reset();
        return 84;
    }
    (color == true) ? green() : 0;
    if (details == true)
        print_test_strncmp(src, my_strncmp);
    else
        (test_function_strncmp(src, my_strncmp) == 0) ?
        printf("\nstrncmp : OK\n") : (((color == true) ? red() : 0),
        printf("\nstrncmp :/!\\ BAD /!\\\n"));
    reset();
    return 0;
}
