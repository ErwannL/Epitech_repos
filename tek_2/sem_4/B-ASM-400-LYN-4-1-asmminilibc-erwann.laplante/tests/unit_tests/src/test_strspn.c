/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strspn
*/

#include "../include/unit_test.h"

size_t test_my_strspn(const char *__s, const char *__reject)
{
    char *lib = "./libasm.so";
    void *handle = dlopen(lib, RTLD_LAZY);
    char *error = dlerror();
    size_t (*my_strspn)(const char *__s, const char *__reject);

    if (!handle || error != NULL) {
        printf("\nPas de lib %s\n%s\n", lib, error);
        return 84;
    } else {
        my_strspn = dlsym(handle, "strspn");
        error = dlerror();
        if (!my_strspn) {
            printf("\nErreur dans strspn %s\n", error);
            return 84;
        }
    }
    return my_strspn(__s, __reject);
}

Test(test_my_strspn, no_in_test) {
    char *src = "Hello World";

    cr_assert_eq(strspn(src, "z"), test_my_strspn(src, "z"));
}

Test(test_my_strspn, in_test) {
    char *src = "Hello World";

    cr_assert_eq(strspn(src,"H"), test_my_strspn(src, "H"));
}

Test(test_my_strspn, multi_in_test) {
    char *src = "Hello World";

    cr_assert_eq(strspn(src, "He"), test_my_strspn(src, "He"));
}

Test(test_my_strspn, far_in_test) {
    char *src = "Hello World";

    cr_assert_eq(strspn(src, "d"), test_my_strspn(src, "d"));
}
