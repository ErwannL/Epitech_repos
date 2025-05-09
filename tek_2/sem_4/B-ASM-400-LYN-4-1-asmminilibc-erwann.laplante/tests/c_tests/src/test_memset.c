/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_memset
*/

#include "../include/c_test.h"

void print_test_memset(char *src, void *(*my_memset)(void *, int, size_t))
{
    char *test = strdup(src);
    char *my_test = strdup(src);
    char *test2 = strdup(src);
    char *my_test2 = strdup(src);
    char *test3 = NULL;
    char *my_test3 = NULL;

    memset(test + 2, '.', 5 * sizeof(char));
    my_memset(my_test + 2, '.', 5 * sizeof(char));
    memset(test2, 0, 5 * sizeof(int));
    my_memset(my_test2, 0, 5 * sizeof(int));
    memset(test3, 'H', 0);
    my_memset(my_test3, 'H', 0);
    printf ("\nmemset = %s | my_memset = %s\n", test, my_test);
    printf ("memset = %i           | my_memset = %i\n", test2[0],
        my_test2[0]);
    printf ("memset = %s      | my_memset = %s\n", test3, my_test3);
}

int test_function_memset(char *src, void *(*my_memset)(void *, int, size_t))
{
    char *test = strdup(src);
    char *my_test = strdup(src);
    char *test2 = strdup(src);
    char *my_test2 = strdup(src);
    char *test3 = NULL;
    char *my_test3 = NULL;

    memset(test + 2, '.', 5 * sizeof(char));
    my_memset(my_test + 2, '.', 5 * sizeof(char));
    memset(test2, 0, 5 * sizeof(int));
    my_memset(my_test2, 0, 5 * sizeof(int));
    memset(test3, 'H', 0);
    my_memset(my_test3, 'H', 0);
    return (strcmp(test, my_test) == 0 && test2[0] == my_test2[0]
        && test3 == my_test3 ? 0 : 84);
}

int test_memset(char *src, void *handle, bool color, bool details)
{
    char *error;
    void *(*my_memset)(void *, int, size_t);

    my_memset = dlsym (handle, "memset");
    error = dlerror();
    if (!my_memset) {
        (color == true) ? red() : 0;
        printf("\nErreur dans memset %s\n", error);
        reset();
        return 84;
    }
    (color == true) ? green() : 0;
    if (details == true)
        print_test_memset(src, my_memset);
    else
        (test_function_memset(src, my_memset) == 0) ? printf("\nmemset : OK\n")
        : (((color == true) ? red() : 0),
        printf("\nmemset :/!\\ BAD /!\\\n"));
    reset();
    return 0;
}
