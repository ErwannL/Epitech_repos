/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strrchr
*/

#include "../include/unit_test.h"

char *test_my_strrchr(const char *__s, int __c)
{
    char *lib = "./libasm.so";
    void *handle = dlopen(lib, RTLD_LAZY);
    char *error = dlerror();
    char *(*my_strrchr)(const char *__s, int __c);

    if (!handle || error != NULL) {
        printf("\nPas de lib %s\n%s\n", lib, error);
        return NULL;
    } else {
        my_strrchr = dlsym(handle, "strrchr");
        error = dlerror();
        if (!my_strrchr) {
            printf("\nErreur dans strrchr %s\n", error);
            return NULL;
        }
    }
    return my_strrchr(__s, __c);
}

Test(test_my_strrchr, in_test) {
    char *src = "Hello World";

    cr_assert(strrchr(src, 'e') == test_my_strrchr(src, 'e'));
}

Test(test_my_strrchr, multi_in_test) {
    char *src = "Hello World";

    cr_assert(strrchr(src, 'l') == test_my_strrchr(src, 'l'));
}

Test(test_my_strrchr, not_in_test) {
    char *src = "Hello World";

    cr_assert(strrchr(src, 'a') == test_my_strrchr(src, 'a'));
}

Test(test_my_strrchr, no_char_test) {
    char *src = "Hello World";

    cr_assert(strrchr(src, '\0')[0] == test_my_strrchr(src, '\0')[0]);
}
