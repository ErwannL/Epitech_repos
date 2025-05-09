/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strcasecmp
*/

#include "../include/unit_test.h"

int test_my_strcasecmp(const char *__s1, const char *__s2)
{
    char *lib = "./libasm.so";
    void *handle = dlopen(lib, RTLD_LAZY);
    char *error = dlerror();
    int (*my_strcasecmp)(const char *__s1, const char *__s2);

    if (!handle || error != NULL) {
        printf("\nPas de lib %s\n%s\n", lib, error);
        return 84;
    } else {
        my_strcasecmp = dlsym(handle, "strcasecmp");
        error = dlerror();
        if (!my_strcasecmp) {
            printf("\nErreur dans strcasecmp %s\n", error);
            return 84;
        }
    }
    return my_strcasecmp(__s1, __s2);
}

Test(test_my_strcasecmp, normal_test) {
    char *src = "Hello World";

    cr_assert_eq(strcasecmp(src, "Hello World"), test_my_strcasecmp(src,
        "Hello World"));
}

Test(test_my_strcasecmp, upper_test) {
    char *src = "Hello World";

    cr_assert_eq(strcasecmp(src, "HEllo Word"), test_my_strcasecmp(src,
        "HEllo Word"));
}

Test(test_my_strcasecmp, lower_test) {
    char *src = "Hello World";

    cr_assert_eq(strcasecmp(src, "hello World nop"), test_my_strcasecmp(src,
        "hello World nop"));
}

Test(test_my_strcasecmp, null_test) {
    char *src = "Hello World";

    cr_assert_eq(strcasecmp(src, ""), test_my_strcasecmp(src, ""));
}
