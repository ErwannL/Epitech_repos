/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strncmp
*/

#include "../include/unit_test.h"

int test_my_strncmp(const char *__s1, const char *__s2, size_t __n)
{
    char *lib = "./libasm.so";
    void *handle = dlopen(lib, RTLD_LAZY);
    char *error = dlerror();
    int (*my_strncmp)(const char *__s1, const char *__s2, size_t __n);

    if (!handle || error != NULL) {
        printf("\nPas de lib %s\n%s\n", lib, error);
        return 84;
    } else {
        my_strncmp = dlsym(handle, "strncmp");
        error = dlerror();
        if (!my_strncmp) {
            printf("\nErreur dans strncmp %s\n", error);
            return 84;
        }
    }
    return my_strncmp(__s1, __s2, __n);
}

Test(test_my_strncmp, normal_test) {
    char *src = "Hello World";

    cr_assert_eq(strncmp(src, "Hello World", 20), test_my_strncmp(src,
        "Hello World", 20));
}

Test(test_my_strncmp, n_test) {
    char *src = "Hello World";

    cr_assert_eq(strncmp(src, "Hello Word", 9), test_my_strncmp(src,
        "Hello Word", 9));
}

Test(test_my_strncmp, neg_test) {
    char *src = "Hello World";

    cr_assert_eq(strncmp(src, "Hello World nop", 20), test_my_strncmp(src,
        "Hello World nop", 20));
}

Test(test_my_strncmp, null_test) {
    char *src = "Hello World";

    cr_assert_eq(strncmp(src, "Hello", 0), test_my_strncmp(src, "Hello", 0));
}
