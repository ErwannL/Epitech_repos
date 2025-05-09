/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_rindex
*/

#include "../include/unit_test.h"

char *test_my_rindex(const char *__s, int __c)
{
    char *lib = "./libasm.so";
    void *handle = dlopen(lib, RTLD_LAZY);
    char *error = dlerror();
    char *(*my_rindex)(const char *__s, int __c);

    if (!handle || error != NULL) {
        printf("\nPas de lib %s\n%s\n", lib, error);
        return NULL;
    } else {
        my_rindex = dlsym(handle, "rindex");
        error = dlerror();
        if (!my_rindex) {
            printf("\nErreur dans rindex %s\n", error);
            return NULL;
        }
    }
    return my_rindex(__s, __c);
}

Test(test_my_rindex, in_test) {
    char *src = "Hello World";

    cr_assert(rindex(src, 'e') == test_my_rindex(src, 'e'));
}

Test(test_my_rindex, multi_in_test) {
    char *src = "Hello World";

    cr_assert(rindex(src, 'l') == test_my_rindex(src, 'l'));
}

Test(test_my_rindex, not_in_test) {
    char *src = "Hello World";

    cr_assert(rindex(src, 'a') == test_my_rindex(src, 'a'));
}

Test(test_my_rindex, no_char_test) {
    char *src = "Hello World";

    cr_assert(rindex(src, '\0')[0] == test_my_rindex(src, '\0')[0]);
}
