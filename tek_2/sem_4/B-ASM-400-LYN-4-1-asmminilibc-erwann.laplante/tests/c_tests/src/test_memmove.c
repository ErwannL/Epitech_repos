/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_memmove
*/

#include "../include/c_test.h"

my_test_t init_struct_memmove(void)
{
    my_test_t my_test_value;

    my_test_value.test = strdup("Bonjour");
    my_test_value.my_test = strdup("Bonjour");
    my_test_value.test2 = strdup("Salut toi, belle journée non ?");
    my_test_value.my_test2 = strdup("Salut toi, belle journée non ?");
    my_test_value.test3 = strdup("Oui");
    my_test_value.my_test3 = strdup("Oui");
    my_test_value.test4 = strdup("Hello World");
    my_test_value.my_test4 = strdup("Hello World");
    my_test_value.test5 = strdup("Hello World");
    my_test_value.my_test5 = strdup("Hello World");
    my_test_value.test6 = NULL;
    my_test_value.my_test6 = NULL;
    return my_test_value;
}

my_test_t setup_struct_memmove(my_test_t my_test_value, char *src,
    void *(*my_memmove)(void *, const void *, size_t))
{
    memmove(my_test_value.test, src, 11);
    my_memmove(my_test_value.my_test, src, 11);
    memmove(my_test_value.test2, src, 5);
    my_memmove(my_test_value.my_test2, src, 5);
    memmove(my_test_value.test3, src, 5);
    my_memmove(my_test_value.my_test3, src, 5);
    memmove(my_test_value.test4 + 2, src, 5 * sizeof(char));
    my_memmove(my_test_value.my_test4 + 2, src, 5 * sizeof(char));
    memmove(my_test_value.test5, src, 5 * sizeof(int));
    my_memmove(my_test_value.my_test5, src, 5 * sizeof(int));
    memmove(my_test_value.test6, src, 0);
    my_memmove(my_test_value.my_test6, src, 0);
    return my_test_value;
}

void print_test_memmove(char *src, void *(*my_memmove)(void *, const void *,
    size_t))
{
    my_test_t my_test_value = setup_struct_memmove(init_struct_memmove(), src,
        my_memmove);

    printf ("\nmemmove = %s                    | my_memmove = %s\n",
        my_test_value.test, my_test_value.my_test);
    printf ("memmove = %s | my_memmove = %s\n",my_test_value.test2,
        my_test_value.my_test2);
    printf ("memmove = %s                          | my_memmove = %s\n",
        my_test_value.test3, my_test_value.my_test3);
    printf ("memmove = %s                    | my_memmove = %s\n",
        my_test_value.test4, my_test_value.my_test4);
    printf ("memmove = %s                    | my_memmove = %s\n",
        my_test_value.test5, my_test_value.my_test5);
    printf ("memmove = %s                         | my_memmove = %s\n",
        my_test_value.test6, my_test_value.my_test6);
}

int test_function_memmove(char *src, void *(*my_memmove)(void *, const void *,
    size_t))
{
    my_test_t my_test_value = setup_struct_memmove(init_struct_memmove(), src,
        my_memmove);

    return (strcmp(my_test_value.test, my_test_value.my_test) == 0
        && strcmp(memmove(my_test_value.test2, src, 11),
            my_memmove(my_test_value.my_test2, src, 11)) == 0
        && strcmp(memmove(my_test_value.test3, src, 5),
            my_memmove(my_test_value.my_test3, src, 5)) == 0
        && strcmp(memmove(my_test_value.test4 + 2, src, 5 * sizeof(char)),
            my_memmove(my_test_value.my_test4 + 2, src, 5 * sizeof(char))) == 0
        && strcmp(memmove(my_test_value.test5, src, 5 * sizeof(int)),
            my_memmove(my_test_value.my_test5, src, 5 * sizeof(int))) == 0
        && memmove(my_test_value.test6, src,
            0) == my_memmove(my_test_value.my_test6, src, 0)
        ? 0 : 84);
}

int test_memmove(char *src, void *handle, bool color, bool details)
{
    char *error;
    void *(*my_memmove)(void *, const void *, size_t);

    my_memmove = dlsym (handle, "memmove");
    error = dlerror();
    if (!my_memmove) {
        (color == true) ? red() : 0;
        printf("\nErreur dans memmove %s\n", error);
        reset();
        return 84;
    }
    (color == true) ? green() : 0;
    if (details == true)
        print_test_memmove(src, my_memmove);
    else
        (test_function_memmove(src, my_memmove) == 0) ?
        printf("\nmemmove : OK\n") : (((color == true) ? red() : 0),
        printf("\nmemmove :/!\\ BAD /!\\\n"));
    reset();
    return 0;
}
