/*
** EPITECH PROJECT, 2022
** private_palindrome
** File description:
** convert
*/

#include "lib.h"

char convert_char(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

char *convert_from_deci(int base, int num)
{
    int index = 0;
    char *res = NULL;
    int tmp = num;
    int len = 0;

    for (; tmp > 0; len++, tmp /= base);
    res = malloc(sizeof(char) * (len + 1));
    for (; num > 0; num /= base)
        res[index++] = convert_char(num % base);
    res[index] = '\0';
    res = my_revstr(res);
    return res;
}

int convert_int(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

int convert_to_deci(char *str, int base)
{
    int len = strlen(str);
    int power = 1;
    int res = 0;

    for (int i = len - 1; i >= 0; i--, power = power * base)
        res += convert_int(str[i]) * power;
    free(str);
    return res;
}
