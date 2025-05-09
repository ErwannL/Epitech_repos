/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strcspn
*/

#include "../include/unit_test.h"

size_t test_my_strcspn(const char *__s, const char *__reject)
{
    char *lib = "./libasm.so";
    void *handle = dlopen(lib, RTLD_LAZY);
    char *error = dlerror();
    size_t (*my_strcspn)(const char *__s, const char *__reject);

    if (!handle || error != NULL) {
        printf("\nPas de lib %s\n%s\n", lib, error);
        return 84;
    } else {
        my_strcspn = dlsym(handle, "strcspn");
        error = dlerror();
        if (!my_strcspn) {
            printf("\nErreur dans strcspn %s\n", error);
            return 84;
        }
    }
    return my_strcspn(__s, __reject);
}

Test(test_my_strcspn, no_in_test) {
    char *src = "Hello World";

    cr_assert_eq(strcspn(src, "z"), test_my_strcspn(src, "z"));
}

Test(test_my_strcspn, in_test) {
    char *src = "Hello World";

    cr_assert_eq(strcspn(src,"e"), test_my_strcspn(src, "e"));
}

Test(test_my_strcspn, multi_in_test) {
    char *src = "Hello World";

    cr_assert_eq(strcspn(src, "ll"), test_my_strcspn(src, "ll"));
}

Test(test_my_strcspn, first_test) {
    char *src = "Hello World";

    cr_assert_eq(strcspn(src, "He"), test_my_strcspn(src, "He"));
}
