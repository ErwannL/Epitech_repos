/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_memmove
*/

#include "../include/unit_test.h"

void *test_my_memmove(void *__dest, const void *__src, size_t __n)
{
    char *lib = "./libasm.so";
    void *handle = dlopen(lib, RTLD_LAZY);
    char *error = dlerror();
    void *(*my_memmove)(void *__dest, const void *__src, size_t __n);

    if (!handle || error != NULL) {
        printf("\nPas de lib %s\n%s\n", lib, error);
        return NULL;
    } else {
        my_memmove = dlsym(handle, "memmove");
        error = dlerror();
        if (!my_memmove) {
            printf("\nErreur dans memmove %s\n", error);
            return NULL;
        }
    }
    return my_memmove(__dest, __src, __n);
}

Test(test_my_memmove, normal_test) {
    char *src = strdup("Hello World");
    char *test = strdup("Salut toi, belle journée non ?");
    char *my_test = strdup("Salut toi, belle journée non ?");

    cr_assert_str_eq(memmove(test, src, 5), test_my_memmove(my_test, src, 5));
}

Test(test_my_memmove, char_test) {
    char *src = strdup("Hello World");
    char *test = strdup("Hello World");
    char *my_test = strdup("Hello World");

    cr_assert_str_eq(memmove(test + 2, src, 5 * sizeof(char)),
        test_my_memmove(my_test + 2, src, 5 * sizeof(char)));
}

Test(test_my_memmove, int_test) {
    char *src = strdup("Hello World");
    char *test = strdup("Hello World");
    char *my_test = strdup("Hello World");

    cr_assert_str_eq(memmove(test, src, 5 * sizeof(int)),
        test_my_memmove(my_test, src, 5 * sizeof(int)));
}

Test(test_my_memmove, null_test) {
    char *src = strdup("Hello World");
    char *test = NULL;
    char *my_test = NULL;

    cr_assert_eq(memmove(test, src, 0), test_my_memmove(my_test, src, 0));
}
