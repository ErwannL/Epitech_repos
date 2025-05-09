/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_my_strlen
*/

#include "../include/unit_test.h"

size_t test_my_strlen(const char *__s)
{
    char *lib = "./libasm.so";
    void *handle = dlopen(lib, RTLD_LAZY);
    char *error = dlerror();
    size_t (*my_strlen)(const char *__s);

    if (!handle || error != NULL) {
        printf("\nPas de lib %s\n%s\n", lib, error);
        return 84;
    } else {
        my_strlen = dlsym(handle, "strlen");
        error = dlerror();
        if (!my_strlen) {
            printf("\nErreur dans strlen %s\n", error);
            return 84;
        }
    }
    return my_strlen(__s);
}

Test(test_my_strlen, normal_test) {
    char *str = "Hello World";

    cr_assert(test_my_strlen(str) == strlen(str));
}

Test(test_my_strlen, empty_test) {
    char *str = "";

    cr_assert(test_my_strlen(str) == strlen(str));
}

Test(test_my_strlen, other_test) {
    char *str = "Bonjour";

    cr_assert(test_my_strlen(str) == strlen(str));
}
