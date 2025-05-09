/*
** EPITECH PROJECT, 2021
** InfinAdd
** File description:
** description
*/
#include"my.h"
#include <stdlib.h>
#include <stddef.h>

int is_neg(char *number)
{
    if (number[0] == '-')
        return (1);
    else
        return (0);
}

void sous_param(int is_neg1, int is_neg2, char *s1, char *s2)
{
    char *tempo;

    if (is_neg1 == 0 && is_neg2 == 1) {
        tempo = s1;
        s1 = s2;
        s2 = tempo;
    }
    s1++;
    if (my_strcmp(s1, s2) > 0) {
        my_putchar('-');
        infin_sous(s1, s2);
    } else {
        infin_sous(s2, s1);
    }
}

void infin_sous(char *s1, char *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    char *result = my_alloc(len1 + 1);
    int save_len = len1;
    int pos = len1;
    int carreed = 0;
    int signed res;

    string_to_val(s1, len1);
    string_to_val(s2, len2);
    len1--;
    len2--;
    while (pos > 0) {
        res = s1[len1] - (len2 < 0 ? 0 : s2[len2]) - carreed;
        ((res < 0) ? (result[pos] = 10 + res) : (result[pos] = res));
        ((res < 0) ? (carreed = 1) : (carreed = 0));
        pos--;
        len1--;
        len2--;
    }
    show_result_to_char(result, save_len + 1);
}
