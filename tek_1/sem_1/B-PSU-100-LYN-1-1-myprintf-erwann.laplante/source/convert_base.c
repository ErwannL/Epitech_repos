/*
** EPITECH PROJECT, 2021
** B-PSU-100-LYN-1-1-myprintf-erwann.laplante
** File description:
** convert_base
*/

#include "../includes/my.h"

void convert_base_bi(int nbr)
{
    int *stock = NULL;
    int i = 0;
    char *number;
    int save = nbr;
    int n = 0;

    for (; nbr > 1; n++)
        nbr /= 2;
    nbr = save;
    stock = (int *)(malloc(sizeof(int) * n));
    for (;nbr >= 2; i++, nbr /= 2)
        stock[i] = nbr % 2;
    stock[i] = nbr;
    i++;
    number = (char *)(malloc(sizeof(char) * n));
    for (int j = 0; j != i; j++)
        number[j] = stock[j] + '0';
    my_putstr(my_rev_str(number));
}

char *convert_base_oct(int nbr)
{
    int *stock = NULL;
    int i = 0;
    char *number;
    int save = nbr;
    int n = 0;

    for (; nbr > 7; n++)
        nbr /= 8;
    nbr = save;
    stock = (int *)(malloc(sizeof(int) * n));
    for (; nbr >= 8; i++, nbr /= 8)
        stock[i] = nbr % 8;
    stock[i] = nbr;
    i++;
    number = (char *)(malloc(sizeof(char) * n));
    for (int j = 0; j != i; j++)
        number[j] = stock[j] + '0';
    return (my_rev_str(number));
}
