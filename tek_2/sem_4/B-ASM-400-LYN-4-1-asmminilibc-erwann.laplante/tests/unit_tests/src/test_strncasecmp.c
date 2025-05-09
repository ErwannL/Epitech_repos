/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strncasecmp
*/

#include "../include/unit_test.h"

int test_my_strncasecmp(const char *__s1, const char *__s2, size_t __n)
{
    char *lib = "./libasm.so";
    void *handle = dlopen(lib, RTLD_LAZY);
    char *error = dlerror();
    int (*my_strncasecmp)(const char *__s1, const char *__s2, size_t __n);

    if (!handle || error != NULL) {
        printf("\nPas de lib %s\n%s\n", lib, error);
        return 84;
    } else {
        my_strncasecmp = dlsym(handle, "strncasecmp");
        error = dlerror();
        if (!my_strncasecmp) {
            printf("\nErreur dans strncasecmp %s\n", error);
            return 84;
        }
    }
    return my_strncasecmp(__s1, __s2, __n);
}

Test(test_my_strncasecmp, normal_test) {
    char *src = "Hello World";

    cr_assert_eq(strncasecmp(src, "Hello World", 11), test_my_strncasecmp(src,
        "Hello World", 11));
}

Test(test_my_strncasecmp, n_test) {
    char *src = "Hello World";

    cr_assert_eq(strncasecmp(src, "Hello world", 5), test_my_strncasecmp(src,
        "Hello world", 5));
}

Test(test_my_strncasecmp, big_test) {
    char *src = "Hello World";

    cr_assert_eq(strncasecmp(src, "Hello Worl", 11), test_my_strncasecmp(src,
        "Hello Worl", 11));
}

Test(test_my_strncasecmp, end_n_test) {
    char *src = "Hello World";

    cr_assert_eq(strncasecmp(src, "Hello World nop", 11),
        test_my_strncasecmp(src, "Hello World nop", 11));
}
