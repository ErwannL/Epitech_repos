/*
** EPITECH PROJECT, 2023
** B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
** File description:
** c_test
*/

#ifndef C_TEST_H_
    #define C_TEST_H_

    #include <dlfcn.h>
    #include <stdio.h>
    #include <string.h>
    #include <strings.h>
    #include <stdbool.h>
    #include <stdlib.h>

    typedef struct my_test {
        char *test;
        char *my_test;
        char *test2;
        char *my_test2;
        char *test3;
        char *my_test3;
        char *test4;
        char *my_test4;
        char *test5;
        char *my_test5;
        char *test6;
        char *my_test6;
    } my_test_t;

    typedef struct pars {
        bool color;
        bool details;
        bool bonus;
        int r;
    } pars_t;

    //color.c
    void red(void);
    void green(void);
    void reset(void);

    //test_strcspn.c
    int test_strcspn(char *src, void *handle, bool color, bool details);

    //test_strpbrk.c
    int test_strpbrk(char *src, void *handle, bool color, bool details);

    //test_strstr.c
    int test_strstr(char *src, void *handle, bool color, bool details);

    //test_strcasecmp.c
    int test_strcasecmp(char *src, void *handle, bool color, bool details);

    //test_strncmp.c
    int test_strncmp(char *src, void *handle, bool color, bool details);

    //test_memmove.c
    int test_memmove(char *src, void *handle, bool color, bool details);

    //test_strcmp.c
    int test_strcmp(char *src, void *handle, bool color, bool details);

    //test_memcpy.c
    int test_memcpy(char *src, void *handle, bool color, bool details);

    //test_memset.c
    int test_memset(char *src, void *handle, bool color, bool details);

    //test_function_strrchr.c
    int test_strrchr(char *src, void *handle, bool color, bool details);

    //test_strchr.c
    int test_strchr(char *src, void *handle, bool color, bool details);

    //test_strlen.c
    int test_strlen(char *src, void *handle, bool color, bool details);

    //help.c
    void print_help(void);

    //args.c
    pars_t pars_args(int ac, char **av, int i, pars_t my_pars);

            //bonus

    //test_strncasecmp.c
    int test_strncasecmp(char *src, void *handle, bool color, bool details);

    //test_strspn.c
    int test_strspn(char *src, void *handle, bool color, bool details);

    //test_function_rindex.c
    int test_rindex(char *src, void *handle, bool color, bool details);

    //test_index.c
    int test_index(char *src, void *handle, bool color, bool details);

#endif /* !C_TEST_H_ */
