/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strstr
*/

#include "../include/c_test.h"

void print_test_strstr(char *src, char *(*my_strstr)(const char *,
    const char *))
{
    printf ("\nstrstr = %s    | my_strstr = %s\n", strstr(src, "lo"),
        my_strstr(src, "lo"));
    printf ("strstr = %s        | my_strstr = %s\n", strstr(src, "or"),
        my_strstr(src, "or"));
    printf ("strstr = %s      | my_strstr = %s\n", strstr(src, "la"),
        my_strstr(src, "la"));
    printf ("strstr = %s | my_strstr = %s\n", strstr(src, ""),
        my_strstr(src, ""));
    printf ("strstr = %s | my_strstr = %s\n", strstr(src, src),
        my_strstr(src, src));
}

int test_function_strstr(char *src, char *(*my_strstr)(const char *,
    const char *))
{
    return (strcmp(strstr(src, "lo"), my_strstr(src, "lo")) == 0
        && strcmp(strstr(src, "or"), my_strstr(src, "or")) == 0
        && strstr(src, "la") == my_strstr(src, "la")
        && strcmp(strstr(src, ""), my_strstr(src, "")) == 0
        && strcmp(strstr(src, src), my_strstr(src, src)) == 0
        ? 0 : 84);
}

int test_strstr(char *src, void *handle, bool color, bool details)
{
    char *error;
    char *(*my_strstr)(const char *, const char *);

    my_strstr = dlsym (handle, "strstr");
    error = dlerror();
    if (!my_strstr) {
        (color == true) ? red() : 0;
        printf("\nErreur dans strstr %s\n", error);
        reset();
        return 84;
    }
    (color == true) ? green() : 0;
    if (details == true)
        print_test_strstr(src, my_strstr);
    else
        (test_function_strstr(src, my_strstr) == 0) ? printf("\nstrstr : OK\n")
        : (((color == true) ? red() : 0),
        printf("\nstrstr :/!\\ BAD /!\\\n"));
    reset();
    return 0;
}
