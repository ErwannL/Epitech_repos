/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strrchr
*/

#include "../include/c_test.h"

void print_test_strrchr(char *src, char *(*my_strrchr)(const char *, int))
{
    printf ("\nstrrchr = %s | my_strrchr = %s\n", strrchr(src, 'e'),
        my_strrchr(src, 'e'));
    printf ("strrchr = %s         | my_strrchr = %s\n", strrchr(src, 'l'),
        my_strrchr(src, 'l'));
    printf ("strrchr = %s     | my_strrchr = %s\n", strrchr(src, 'a'),
        my_strrchr(src, 'a'));
    printf ("strrchr = %s     | my_strrchr = %s\n", strrchr("", 'a'),
        my_strrchr("", 'a'));
    printf ("strrchr = %i          | my_strrchr = %i\n", strrchr(src, '\0')[0],
        my_strrchr(src, '\0')[0]);
    printf ("strrchr = %i          | my_strrchr = %i\n", strrchr("", '\0')[0],
        my_strrchr("", '\0')[0]);
}

int test_function_strrchr(char *src, char *(*my_strrchr)(const char *, int))
{
    return (strrchr(src, 'e') == my_strrchr(src, 'e')
        && strrchr(src, 'l') == my_strrchr(src, 'l')
        && strrchr(src, 'a') == my_strrchr(src, 'a')
        && strrchr("", 'a') == my_strrchr("", 'a')
        && strrchr(src, '\0')[0] == my_strrchr(src, '\0')[0]
        && strrchr("", '\0')[0] == my_strrchr("", '\0')[0] ? 0 : 84 );
}

int test_strrchr(char *src, void *handle, bool color, bool details)
{
    char *error;
    char *(*my_strrchr)(const char *, int);

    my_strrchr = dlsym (handle, "strrchr");
    error = dlerror();
    if (!my_strrchr) {
        (color == true) ? red() : 0;
        printf("\nErreur dans strrchr %s\n", error);
        reset();
        return 84;
    }
    (color == true) ? green() : 0;
    if (details == true)
        print_test_strrchr(src, my_strrchr);
    else
        (test_function_strrchr(src, my_strrchr) == 0) ?
        printf("\nstrrchr : OK\n") : (((color == true) ? red() : 0),
        printf("\nstrrchr :/!\\ BAD /!\\\n"));
    reset();
    return 0;
}
