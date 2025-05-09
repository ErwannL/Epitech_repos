/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strpbrk
*/

#include "../include/unit_test.h"

char *test_my_strpbrk(const char *__s, const char *__accept)
{
    char *lib = "./libasm.so";
    void *handle = dlopen(lib, RTLD_LAZY);
    char *error = dlerror();
    char *(*my_strpbrk)(const char *__s, const char *__accept);

    if (!handle || error != NULL) {
        printf("\nPas de lib %s\n%s\n", lib, error);
        return NULL;
    } else {
        my_strpbrk = dlsym(handle, "strpbrk");
        error = dlerror();
        if (!my_strpbrk) {
            printf("\nErreur dans strpbrk %s\n", error);
            return NULL;
        }
    }
    return my_strpbrk(__s, __accept);
}

Test(test_my_strpbrk, in_test) {
    char *src = "Hello World";

    cr_assert_str_eq(strpbrk(src, "ezzz"), test_my_strpbrk(src, "ezzz"));
}

Test(test_my_strpbrk, no_test) {
    char *src = "Hello World";

    cr_assert_eq(strpbrk(src, "zzz"), test_my_strpbrk(src, "zzz"));
}

Test(test_my_strpbrk, multi_test) {
    char *src = "Hello World";

    cr_assert_str_eq(strpbrk(src, "lo"), test_my_strpbrk(src, "lo"));
}

Test(test_my_strpbrk, mix_multi_test) {
    char *src = "Hello World";

    cr_assert_str_eq(strpbrk(src, "ol"), test_my_strpbrk(src, "ol"));
}
