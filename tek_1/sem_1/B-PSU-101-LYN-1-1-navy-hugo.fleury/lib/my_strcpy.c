/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** Copies a string into another one.
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (dest == 0 || src == 0) {
        return 0;
    }
    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
