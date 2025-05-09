/*
** EPITECH PROJECT, 2021
** TTask 05 - my_getnbr
** File description:
** This function eturns a number, sent to the function as a string
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int signe = 1;
    long int res = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            signe *= - 1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        res = res * 10 + str[i] - 48;
        if (res > 2147483648 || (res == 2147483648 && signe == 1))
            return (0);
        i++;
    }
    return (res * signe);
}
