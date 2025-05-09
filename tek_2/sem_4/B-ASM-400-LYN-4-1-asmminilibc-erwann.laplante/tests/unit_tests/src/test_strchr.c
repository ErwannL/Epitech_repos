/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strchr
*/

#include "../include/unit_test.h"

char *test_my_strchr(const char *__s, int __c)
{
    char *lib = "./libasm.so";
    void *handle = dlopen(lib, RTLD_LAZY);
    char *error = dlerror();
    char *(*my_strchr)(const char *__s, int __c);

    if (!handle || error != NULL) {
        printf("\nPas de lib %s\n%s\n", lib, error);
        return NULL;
    } else {
        my_strchr = dlsym(handle, "strchr");
        error = dlerror();
        if (!my_strchr) {
            printf("\nErreur dans strchr %s\n", error);
            return NULL;
        }
    }
    return my_strchr(__s, __c);
}

Test(test_my_strchr, in_test) {
    char *src = "Hello World";

    cr_assert(strchr(src, 'e') == test_my_strchr(src, 'e'));
}

Test(test_my_strchr, not_in_test) {
    char *src = "Hello World";

    cr_assert(strchr(src, 'a') == test_my_strchr(src, 'a'));
}

Test(test_my_strchr, empty_str_test) {
    char *src = "";

    cr_assert(strchr(src, 'a') == test_my_strchr(src, 'a'));
}

Test(test_my_strchr, no_char_test) {
    char *src = "Hello World";

    cr_assert(strchr(src, '\0') == test_my_strchr(src, '\0'));
}
