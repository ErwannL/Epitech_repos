/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_rindex
*/

#include "../include/c_test.h"

void print_test_rindex(char *src, char *(*my_rindex)(const char *, int))
{
    printf ("\nrindex = %s | my_rindex = %s\n", rindex(src, 'e'),
        my_rindex(src, 'e'));
    printf ("rindex = %s         | my_rindex = %s\n", rindex(src, 'l'),
        my_rindex(src, 'l'));
    printf ("rindex = %s     | my_rindex = %s\n", rindex(src, 'a'),
        my_rindex(src, 'a'));
    printf ("rindex = %s     | my_rindex = %s\n", rindex("", 'a'),
        my_rindex("", 'a'));
    printf ("rindex = %i          | my_rindex = %i\n", rindex(src, '\0')[0],
        my_rindex(src, '\0')[0]);
    printf ("rindex = %i          | my_rindex = %i\n", rindex("", '\0')[0],
        my_rindex("", '\0')[0]);
}

int test_function_rindex(char *src, char *(*my_rindex)(const char *, int))
{
    return (rindex(src, 'e') == my_rindex(src, 'e')
        && rindex(src, 'l') == my_rindex(src, 'l')
        && rindex(src, 'a') == my_rindex(src, 'a')
        && rindex("", 'a') == my_rindex("", 'a')
        && rindex(src, '\0')[0] == my_rindex(src, '\0')[0]
        && rindex("", '\0')[0] == my_rindex("", '\0')[0] ? 0 : 84 );
}

int test_rindex(char *src, void *handle, bool color, bool details)
{
    char *error;
    char *(*my_rindex)(const char *, int);

    my_rindex = dlsym (handle, "rindex");
    error = dlerror();
    if (!my_rindex) {
        (color == true) ? red() : 0;
        printf("\nErreur dans rindex %s\n", error);
        reset();
        return 84;
    }
    (color == true) ? green() : 0;
    if (details == true)
        print_test_rindex(src, my_rindex);
    else
        (test_function_rindex(src, my_rindex) == 0) ?
        printf("\nrindex : OK\n") : (((color == true) ? red() : 0),
        printf("\nrindex :/!\\ BAD /!\\\n"));
    reset();
    return 0;
}
