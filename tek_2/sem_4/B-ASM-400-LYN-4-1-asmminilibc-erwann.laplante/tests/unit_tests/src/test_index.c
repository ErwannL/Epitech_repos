/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_index
*/

#include "../include/unit_test.h"

char *test_my_index(const char *__s, int __c)
{
    char *lib = "./libasm.so";
    void *handle = dlopen(lib, RTLD_LAZY);
    char *error = dlerror();
    char *(*my_index)(const char *__s, int __c);

    if (!handle || error != NULL) {
        printf("\nPas de lib %s\n%s\n", lib, error);
        return NULL;
    } else {
        my_index = dlsym(handle, "index");
        error = dlerror();
        if (!my_index) {
            printf("\nErreur dans index %s\n", error);
            return NULL;
        }
    }
    return my_index(__s, __c);
}

Test(test_my_index, in_test) {
    char *src = "Hello World";

    cr_assert(index(src, 'e') == test_my_index(src, 'e'));
}

Test(test_my_index, not_in_test) {
    char *src = "Hello World";

    cr_assert(index(src, 'a') == test_my_index(src, 'a'));
}

Test(test_my_index, empty_str_test) {
    char *src = "";

    cr_assert(index(src, 'a') == test_my_index(src, 'a'));
}

Test(test_my_index, no_char_test) {
    char *src = "Hello World";

    cr_assert(index(src, '\0') == test_my_index(src, '\0'));
}
