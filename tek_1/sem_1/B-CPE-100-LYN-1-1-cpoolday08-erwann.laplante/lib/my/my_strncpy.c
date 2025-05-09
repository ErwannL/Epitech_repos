/*
** EPITECH PROJECT, 2021
** Task 02 - my_strncpy
** File description:
** This function copies n characters from a string into another.
*/

int my_strlen5(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strncpy(char *dest , char const *src , int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n > my_strlen5(src))
        dest[i] = '\0';
    return (dest);
}
