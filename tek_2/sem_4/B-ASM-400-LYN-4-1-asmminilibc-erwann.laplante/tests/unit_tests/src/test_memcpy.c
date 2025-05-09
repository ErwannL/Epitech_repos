/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_memcpy
*/

#include "../include/unit_test.h"

void *test_my_memcpy(void *__dest, const void *__src, size_t __n)
{
    char *lib = "./libasm.so";
    void *handle = dlopen(lib, RTLD_LAZY);
    char *error = dlerror();
    void *(*my_memcpy)(void *__dest, const void *__src, size_t __n);

    if (!handle || error != NULL) {
        printf("\nPas de lib %s\n%s\n", lib, error);
        return NULL;
    } else {
        my_memcpy = dlsym(handle, "memcpy");
        error = dlerror();
        if (!my_memcpy) {
            printf("\nErreur dans memcpy %s\n", error);
            return NULL;
        }
    }
    return my_memcpy(__dest, __src, __n);
}

Test(test_my_memcpy, normal_test) {
    char src[12] = "Hello World";
    char *test = strdup("");
    char *my_test = strdup("");

    memcpy(test, src, sizeof(src));
    test_my_memcpy(my_test, src, sizeof(src));
    cr_assert_str_eq(test, my_test);
}

Test(test_my_memcpy, already_exist_test) {
    char src[12] = "Hello World";
    char *test = strdup("aba");
    char *my_test = strdup("aba");

    memcpy(test, src, sizeof(src));
    test_my_memcpy(my_test, src, sizeof(src));
    cr_assert_str_eq(test, my_test);
}

Test(test_my_memcpy, big_test) {
    char src[12] = "Hello World";
    char *test = strdup("Hello World nop");
    char *my_test = strdup("Hello World nop");

    memcpy(test, src, sizeof(src));
    test_my_memcpy(my_test, src, sizeof(src));
    cr_assert_str_eq(test, my_test);
}
