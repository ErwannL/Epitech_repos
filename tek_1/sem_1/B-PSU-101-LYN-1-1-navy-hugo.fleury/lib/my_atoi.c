/*
** EPITECH PROJECT, 2021
** my_atoi
** File description:
** libc 'my_atoi' but recoded.
*/

#include "my.h"

int my_atoi(char *str)
{
    int i = 0;
    int ret = 0;
    int neg = 1;

    ((str[i] == '-') ? (neg = -1, i += 1) : 0);
    for (; str[i] != '\0'; i++) {
        ret = (ret * 10) + (str[i] - '0');
    }
    return (ret * neg);
}
