/*
** EPITECH PROJECT, 2021
** Task 13 - my_str_isnum
** File description:
** function returns 1 if parameter only digits characters and 0 if not
*/

int my_strlen2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_str_isnum(char const *str)
{
    int long_max = my_strlen2(str);
    int longueur = 0;
    int i = 0;

    if (long_max == 0)
        return (1);
    while (str[i] != '\0') {
        if (str[i] >= '0' || str[i] <= '9')
            longueur++;
        i++;
    }
    if (longueur == long_max)
        return (1);
    return (0);
}
