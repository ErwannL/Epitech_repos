/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** test
*/

#include "../include/c_test.h"

int is_bonus_tested(char *src, void *handle,pars_t my_pars)
{
    if (my_pars.bonus == false)
        return 0;
    return (test_strncasecmp(src, handle, my_pars.color, my_pars.details) == 84
        || test_strspn(src, handle, my_pars.color, my_pars.details) == 84
        || test_index(src, handle, my_pars.color, my_pars.details) == 84
        || test_rindex(src, handle, my_pars.color, my_pars.details) == 84
        ? 84 : 0);
}

int execute_all_tests(char *src, void *handle,pars_t my_pars)
{
    return (test_strlen(src, handle, my_pars.color, my_pars.details) == 84
        || test_strchr(src, handle, my_pars.color, my_pars.details) == 84
        || test_strrchr(src, handle, my_pars.color, my_pars.details) == 84
        || test_memset(src, handle, my_pars.color, my_pars.details) == 84
        || test_memcpy(src, handle, my_pars.color, my_pars.details) == 84
        || test_strcmp(src, handle, my_pars.color, my_pars.details) == 84
        || test_memmove(src, handle, my_pars.color, my_pars.details) == 84
        || test_strncmp(src, handle, my_pars.color, my_pars.details) == 84
        || test_strcasecmp(src, handle, my_pars.color, my_pars.details) == 84
        || test_strstr(src, handle, my_pars.color, my_pars.details) == 84
        || test_strpbrk(src, handle, my_pars.color, my_pars.details) == 84
        || test_strcspn(src, handle, my_pars.color, my_pars.details) == 84
        || is_bonus_tested(src, handle, my_pars) == 84
        ? 84 : 0);
}

int test_functions(pars_t my_pars)
{
    char src[11] = "Hello World";
    char *lib = "./libasm.so";
    void *handle = dlopen(lib, RTLD_LAZY);
    char *error = dlerror();

    if (!handle || error != NULL) {
        (my_pars.color == true) ? red() : 0;
        printf("\nPas de lib %s\n%s\n", lib, error);
        reset();
        return 84;
    }
    if (execute_all_tests(src, handle, my_pars) == 84)
        return 84;
    dlclose(handle);
    return 0;
}

int main (int ac, char **av)
{
    pars_t my_pars;

    my_pars.r = 0;
    my_pars.color = false;
    my_pars.details = false;
    my_pars.bonus = false;
    if (ac == 1) {
        my_pars.color = false;
        my_pars.details = false;
    } else {
        for (int i = 1; av[i]; i++)
            my_pars = pars_args(ac, av, i, my_pars);
        if (my_pars.r == 1)
            return 0;
    }
    return test_functions(my_pars);
}
