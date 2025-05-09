/*
** EPITECH PROJECT, 2021
** Task 03 - my_strncat
** File description:
** print char
*/

char *my_strncat(char *dest , char const *src , int nb)
{
    int i = 0;
    int j = 0;
    int value = 0;

    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0' && value < nb) {
        dest[i] = src[j];
        i++;
        j++;
        value++;
    }
    return (dest);
}
