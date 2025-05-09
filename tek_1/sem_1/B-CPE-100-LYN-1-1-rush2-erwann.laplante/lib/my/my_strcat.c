/*
** EPITECH PROJECT, 2021
** Task 02 - my_strcat
** File description:
** print char
*/

char *my_strcat(char *dest , char src)
{
    int i = 0;

    while (dest[i] != '\0')
        i++;
    dest[i] = src;
    i++;
    return (dest);
}
