/*
** EPITECH PROJECT, 2021
** count_island
** File description:
** This function counts and returns the number of characters found in a string
*/

int my_strlarg(char **str)
{
    int i = 0;

    while (str[0][i] != '\0') {
        i++;
    }
    return (i);
}
