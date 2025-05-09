/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_memset
*/

#include "../include/unit_test.h"

void *test_my_memset(void *__s, int __c, size_t __n)
{
    char *lib = "./libasm.so";
    void *handle = dlopen(lib, RTLD_LAZY);
    char *error = dlerror();
    void *(*my_memset)(void *__s, int __c, size_t __n);

    if (!handle || error != NULL) {
        printf("\nPas de lib %s\n%s\n", lib, error);
        return NULL;
    } else {
        my_memset = dlsym(handle, "memset");
        error = dlerror();
        if (!my_memset) {
            printf("\nErreur dans memset %s\n", error);
            return NULL;
        }
    }
    return my_memset(__s, __c, __n);
}

Test(test_my_memset, normal_test) {
    char *src = "Hello World";
    char *test = strdup(src);
    char *my_test = strdup(src);

    memset(test + 2, '.', 5 * sizeof(char));
    test_my_memset(my_test + 2, '.', 5 * sizeof(char));
    cr_assert_str_eq(test, my_test);
}

Test(test_my_memset, null_test) {
    char *src = "Hello World";
    char *test = strdup(src);
    char *my_test = strdup(src);

    memset(test, 0, 5 * sizeof(int));
    test_my_memset(my_test, 0, 5 * sizeof(int));
    cr_assert_eq(test[0], my_test[0]);
}

Test(test_my_memset, zero_test) {
    char *src = "Hello World";
    char *test = NULL;
    char *my_test = NULL;

    memset(test, 'H', 0);
    test_my_memset(my_test, 'H', 0);
    cr_assert_eq(test, my_test);
}
