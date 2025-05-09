/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** mini lib c
*/

#include "my_rpg.h"

char *my_strdup(char *src)
{
    int i = 0;
    char *ret = NULL;

    if (src == NULL)
        return NULL;
    ret = (char *)malloc(sizeof(char) * (my_strlen_two(NULL, src, 0) + 1));
    for (; src[i] != '\0'; ret[i] = src[i], i++);
    ret[i] = '\0';
    return ret;
}

char *my_revstr(char *str)
{
    char substitute;
    int length = 0;

    if (str == 0)
        return 0;
    for (; str[length] != '\0'; length++);
    length -= 1;
    for (int i = 0; i < length; i++, length--) {
        substitute = str[i];
        str[i] = str[length];
        str[length] = substitute;
    }
    return str;
}

char *my_itoa(int number)
{
    int i = 0;
    char all_bases[] = "0123456789abcdef";
    char *buf = (char *)malloc(sizeof(int) + 1);

    for (i = 0; number != 0; i -= -1) {
        buf[i] = all_bases[(number % 10)];
        number /= 10;
    }
    buf[i] = '\0';
    return my_revstr(buf);
}

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    char *ret = NULL;

    if ((dest == NULL) || (src == NULL))
        return NULL;
    ret = malloc((my_strlen_two(NULL, dest, 0) + my_strlen_two(NULL, src, 0))
    + 1);
    for (; dest[j] != '\0'; ret[j] = dest[j], j++);
    for (; src[i] != '\0'; ret[j + i] = src[i], i++);
    ret[j + i] = '\0';
    return ret;
}

int my_strlen_two(char **array, char *what, int x)
{
    int length = 0;

    if (x == 0) {
        for (; what[length] != '\0'; length++);
    } else {
        for (; *array; length++, array++);
    }
    return length;
}
