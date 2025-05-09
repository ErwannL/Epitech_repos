/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strcmp
*/

#include "../include/unit_test.h"

int test_my_strcmp(const char *__s1, const char *__s2)
{
    char *lib = "./libasm.so";
    void *handle = dlopen(lib, RTLD_LAZY);
    char *error = dlerror();
    int (*my_strcmp)(const char *__s1, const char *__s2);

    if (!handle || error != NULL) {
        printf("\nPas de lib %s\n%s\n", lib, error);
        return 84;
    } else {
        my_strcmp = dlsym(handle, "strcmp");
        error = dlerror();
        if (!my_strcmp) {
            printf("\nErreur dans strcmp %s\n", error);
            return 84;
        }
    }
    return my_strcmp(__s1, __s2);
}

Test(test_my_strcmp, all_test) {
    char *src = "Hello World";

    cr_assert_eq(strcmp(src, "Hello World"), test_my_strcmp(src,
        "Hello World"));
}

Test(test_my_strcmp, pos_test) {
    char *src = "Hello World";

    cr_assert_eq(strcmp(src, "Hello Worl"), test_my_strcmp(src,
        "Hello Worl"));

}

Test(test_my_strcmp, neg_test) {
    char *src = "Hello World";

    cr_assert_eq(strcmp(src, "Hello World nop"), test_my_strcmp(src,
        "Hello World nop"));
}
