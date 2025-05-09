/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strpbrk
*/

#include "../include/c_test.h"

void print_test_strpbrk(char *src, char *(*my_strpbrk)(const char *,
    const char *))
{
    printf ("\nstrpbrk = %s | my_strpbrk = %s\n", strpbrk(src, "ezzz"),
        my_strpbrk(src, "ezzz"));
    printf ("strpbrk = %s     | my_strpbrk = %s\n", strpbrk(src, "zzz"),
        my_strpbrk(src, "zzz"));
    printf ("strpbrk = %s  | my_strpbrk = %s\n", strpbrk(src, "lo"),
        my_strpbrk(src, "lo"));
    printf ("strpbrk = %s  | my_strpbrk = %s\n", strpbrk(src, "ol"),
        my_strpbrk(src, "ol"));
    printf ("strpbrk = %s    | my_strpbrk = %s\n", strpbrk(src, "ozzz"),
        my_strpbrk(src, "ozzz"));
}

int test_function_strpbrk(char *src, char *(*my_strpbrk)(const char *,
    const char *))
{
    return (strcmp(strpbrk(src, "ezzz"), my_strpbrk(src, "ezzz")) == 0
        && strpbrk(src, "zzz") == my_strpbrk(src, "zzz")
        && strcmp(strpbrk(src, "lo"), my_strpbrk(src, "lo")) == 0
        && strcmp(strpbrk(src, "ol"), my_strpbrk(src, "ol")) == 0
        && strcmp(strpbrk(src, "ozzz"), my_strpbrk(src, "ozzz")) == 0
        ? 0 : 84);
}

int test_strpbrk(char *src, void *handle, bool color, bool details)
{
    char *error;
    char *(*my_strpbrk)(const char *, const char *);

    my_strpbrk = dlsym (handle, "strpbrk");
    error = dlerror();
    if (!my_strpbrk) {
        (color == true) ? red() : 0;
        printf("\nErreur dans strpbrk %s\n", error);
        reset();
        return 84;
    }
    (color == true) ? green() : 0;
    if (details == true)
        print_test_strpbrk(src, my_strpbrk);
    else
        (test_function_strpbrk(src, my_strpbrk) == 0) ?
        printf("\nstrpbrk : OK\n") : (((color == true) ? red() : 0),
        printf("\nstrpbrk :/!\\ BAD /!\\\n"));
    reset();
    return 0;
}
