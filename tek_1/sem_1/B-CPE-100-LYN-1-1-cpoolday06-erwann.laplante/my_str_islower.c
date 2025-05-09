/*
** EPITECH PROJECT, 2021
** Task 14 - my_str_islower
** File description:
** function returns 1 if parameter only lower case characters and 0 if not
*/

int my_strlen1(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_str_islower(char const *str)
{
    int long_max = my_strlen1(str);
    int longueur = 0;
    int i = 0;

    if (long_max == 0)
        return (1);
    while (str[i] != '\0') {
        if (str[i] >= 'a' || str[i] <= 'b')
            longueur++;
        i++;
    }
    if (longueur == long_max)
        return (1);
    return (0);
}
