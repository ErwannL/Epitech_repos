/*
** EPITECH PROJECT, 2021
** InfinAdd
** File description:
** description
*/
#include "my.h"
#include <stdlib.h>
#include <stddef.h>

char *my_alloc(int len)
{
    char *to_alloc;
    int i = 0;

    to_alloc = malloc(sizeof(char) * len);
    while (i < len)
        to_alloc[i++] = '\0';
    return (to_alloc);
}

void string_to_val(char *str, int len)
{
    int i = 0;

    while (i < len)
        str[i++] -= '0';
}

void show_result_to_char(char *str, int len)
{
    int zero = 0;
    int i = 0;

    while (i < len) {
        if (zero != 0 || str[i] != 0 || i == len - 1) {
            my_putchar(str[i] + '0');
            zero = 1;
        }
        i++;
    }
    free(str);
}

void infin_add(char *s1, char *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    char *result = my_alloc(len1 + 1);
    int save_len = len1;
    int pos = len1;
    int carreed = 0;
    int res;

    string_to_val(s1, len1);
    string_to_val(s2, len2);
    len1--;
    len2--;
    while (pos > 0) {
        res = s1[len1] + (len2 < 0 ? 0 : s2[len2]) + carreed;
        carreed = res / 10;
        result[pos] = res % 10;
        pos--;
        len1--;
        len2--;
    }
    if (carreed == 1)
        result[0] = 1;
    show_result_to_char(result, save_len + 1);
}

int main(int ac, char **av)
{
    int is_neg1 = is_neg(av[1]);
    int is_neg2 = is_neg(av[2]);

    if (ac == 3) {
        if (is_neg1 == 1 && is_neg2 == 1) {
            my_putchar('-');
            av[1]++;
            av[2]++;
        }
        if (my_strlen(av[1]) >= my_strlen(av[2]) && is_neg1 == is_neg2)
            infin_add(av[1], av[2]);
        else if (my_strlen(av[1]) < my_strlen(av[2]) && is_neg1 == is_neg2)
            infin_add(av[2], av[1]);
        else
            sous_param(is_neg1, is_neg2, av[1], av[2]);
        my_putchar('\n');
        return (0);
    }
    return (84);
}
