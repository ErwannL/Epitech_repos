/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strchr
*/

#include "../include/c_test.h"

void print_test_strchr(char *src, char *(*my_strchr)(const char *, int))
{
    printf ("\nstrchr = %s | my_strchr = %s\n", strchr(src, 'e'),
        my_strchr(src, 'e'));
    printf ("strchr = %s     | my_strchr = %s\n", strchr(src, 'a'),
        my_strchr(src, 'a'));
    printf ("strchr = %s     | my_strchr = %s\n", strchr("", 'a'),
        my_strchr("", 'a'));
    printf ("strchr = %i          | my_strchr = %i\n", strchr(src, '\0')[0],
        my_strchr(src, '\0')[0]);
    printf ("strchr = %i          | my_strchr = %i\n", strchr("", '\0')[0],
        my_strchr("", '\0')[0]);
}

int test_function_strchr(char *src, char *(*my_strchr)(const char *, int))
{
    return (strchr(src, 'e') == my_strchr(src, 'e')
        && strchr(src, 'a') == my_strchr(src, 'a')
        && strchr("", 'a') == my_strchr("", 'a')
        && strchr(src, '\0')[0] == my_strchr(src, '\0')[0]
        && strchr("", '\0')[0] == my_strchr("", '\0')[0] ? 0 : 84);
}

int test_strchr(char *src, void *handle, bool color, bool details)
{
    char *error;
    char *(*my_strchr)(const char *, int);

    my_strchr = dlsym (handle, "strchr");
    error = dlerror();
    if (!my_strchr) {
        (color == true) ? red() : 0;
        printf("\nErreur dans strchr %s\n", error);
        reset();
        return 84;
    }
    (color == true) ? green() : 0;
    if (details == true)
        print_test_strchr(src, strchr);
    else
        (test_function_strchr(src, strchr) == 0) ? printf("\nstrchr : OK\n") :
        (((color == true) ? red() : 0), printf("\nstrchr :/!\\ BAD /!\\\n"));
    reset();
    return 0;
}
