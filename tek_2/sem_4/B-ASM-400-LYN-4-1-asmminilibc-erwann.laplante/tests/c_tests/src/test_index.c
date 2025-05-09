/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_index
*/

#include "../include/c_test.h"

void print_test_index(char *src, char *(*my_index)(const char *, int))
{
    printf ("\nindex = %s | my_index = %s\n", index(src, 'e'),
        my_index(src, 'e'));
    printf ("index = %s     | my_index = %s\n", index(src, 'a'),
        my_index(src, 'a'));
    printf ("index = %s     | my_index = %s\n", index("", 'a'),
        my_index("", 'a'));
    printf ("index = %i          | my_index = %i\n", index(src, '\0')[0],
        my_index(src, '\0')[0]);
    printf ("index = %i          | my_index = %i\n", index("", '\0')[0],
        my_index("", '\0')[0]);
}

int test_function_index(char *src, char *(*my_index)(const char *, int))
{
    return (index(src, 'e') == my_index(src, 'e')
        && index(src, 'a') == my_index(src, 'a')
        && index("", 'a') == my_index("", 'a')
        && index(src, '\0')[0] == my_index(src, '\0')[0]
        && index("", '\0')[0] == my_index("", '\0')[0] ? 0 : 84);
}

int test_index(char *src, void *handle, bool color, bool details)
{
    char *error;
    char *(*my_index)(const char *, int);

    my_index = dlsym (handle, "index");
    error = dlerror();
    if (!my_index) {
        (color == true) ? red() : 0;
        printf("\nErreur dans index %s\n", error);
        reset();
        return 84;
    }
    (color == true) ? green() : 0;
    if (details == true)
        print_test_index(src, index);
    else
        (test_function_index(src, index) == 0) ? printf("\nindex : OK\n") :
        (((color == true) ? red() : 0), printf("\nindex :/!\\ BAD /!\\\n"));
    reset();
    return 0;
}
