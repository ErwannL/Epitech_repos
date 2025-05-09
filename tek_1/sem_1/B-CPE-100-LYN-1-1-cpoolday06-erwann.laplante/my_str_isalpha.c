/*
** EPITECH PROJECT, 2021
** Task 12 - my_str_isalpha
** File description:
** function returns 1 if parameter only alphabetical characters and 0 if not
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_str_isalpha(char const *str)
{
    int long_max = my_strlen(str);
    int longueur = 0;
    int i = 0;

    if (long_max == 0)
        return (1);
    while (str[i] != '\0') {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
            longueur++;
        i++;
    }
    if (longueur == long_max)
        return (1);
    return (0);
}
