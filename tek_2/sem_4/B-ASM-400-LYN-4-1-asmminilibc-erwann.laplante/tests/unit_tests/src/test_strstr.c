/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test_strstr
*/

#include "../include/unit_test.h"

char *test_my_strstr(const char *__haystack, const char *__needle)
{
    char *lib = "./libasm.so";
    void *handle = dlopen(lib, RTLD_LAZY);
    char *error = dlerror();
    char *(*my_strstr)(const char *__haystack, const char *__needle);

    if (!handle || error != NULL) {
        printf("\nPas de lib %s\n%s\n", lib, error);
        return NULL;
    } else {
        my_strstr = dlsym(handle, "strstr");
        error = dlerror();
        if (!my_strstr) {
            printf("\nErreur dans strstr %s\n", error);
            return NULL;
        }
    }
    return my_strstr(__haystack, __needle);
}

Test(test_my_strstr, normal_test) {
    char *src = "Hello World";

    cr_assert_str_eq(strstr(src, "lo"), test_my_strstr(src, "lo"));
}

Test(test_my_strstr, upper_test) {
    char *src = "Hello World";

    cr_assert_str_eq(strstr(src, "or"), test_my_strstr(src, "or"));
}

Test(test_my_strstr, lower_test) {
    char *src = "Hello World";

    cr_assert_eq(strstr(src, "la"), test_my_strstr(src, "la"));
}

Test(test_my_strstr, null_test) {
    char *src = "Hello World";

    cr_assert_str_eq(strstr(src, ""), test_my_strstr(src, ""));
}
