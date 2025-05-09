/*
** EPITECH PROJECT, 2021
** Rush-1
** File description:
** function that displays a star, based on its given size
*/

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}