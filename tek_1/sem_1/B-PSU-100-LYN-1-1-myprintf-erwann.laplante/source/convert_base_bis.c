/*
** EPITECH PROJECT, 2021
** B-PSU-100-LYN-1-1-myprintf-erwann.laplante
** File description:
** convert_base_bis
*/

#include "../includes/my.h"

char *convert_base_hex_maj_bis(int *stock, int i, int n)
{
    char *number = (char *)(malloc(sizeof(char) * n));
    for (int j = 0; j != i; j++) {
        ((stock[j] < 10) ? (number[j] = stock[j] + '0') : ((stock[j] == 10) ? \
        (number[j] = 'A') : ((stock[j] == 11) ? (number[j] = 'B') : ((stock[j]\
        == 12) ? (number[j] = 'C') : ((stock[j] == 13) ? (number[j] = 'D') : (\
        (stock[j] == 14) ? (number[j] = 'E') : (number[j] = 'F')))))));
    }
    while (number[0] == '0')
        number++;
    return (number);
}

void convert_base_hex_maj(int nbr)
{
    int *stock = NULL;
    int i;
    int save = nbr;
    int puissance = 1;
    int n;

    for (; nbr > 0; n++)
        nbr /= 10;
    nbr = save;
    stock = (int *)(malloc(sizeof(int) * n));
    for (; nbr > 16; i++, nbr = nbr - ((nbr / puissance) * puissance)) {
        for (; puissance < nbr; puissance *= 16);
        puissance /= 16;
        stock[i] = nbr / puissance;
    }
    stock[i] = nbr;
    i++;
    my_putstr(convert_base_hex_maj_bis(stock, i, n));
}

char *convert_base_hex_min_bis(int *stock, int i, int n)
{
    char *number = (char *)(malloc(sizeof(char) * n));
    for (int j = 0; j != i; j++) {
        ((stock[j] < 10) ? (number[j] = stock[j] + '0') : ((stock[j] == 10) ? \
        (number[j] = 'a') : ((stock[j] == 11) ? (number[j] = 'b') : ((stock[j]\
        == 12) ? (number[j] = 'c') : ((stock[j] == 13) ? (number[j] = 'd') : (\
        (stock[j] == 14) ? (number[j] = 'e') : (number[j] = 'f')))))));
    }
    while (number[0] == '0')
        number++;
    return (number);
}

void convert_base_hex_min(int nbr)
{
    int *stock = NULL;
    int i;
    int save = nbr;
    int puissance = 1;
    int n;

    for (; nbr > 0; n++)
        nbr /= 10;
    nbr = save;
    stock = (int *)(malloc(sizeof(int) * n));
    for (; nbr > 16; i++, nbr = nbr - ((nbr / puissance) * puissance)) {
        for (; puissance < nbr; puissance *= 16);
        puissance /= 16;
        stock[i] = nbr / puissance;
    }
    stock[i] = nbr;
    i++;
    my_putstr(convert_base_hex_min_bis(stock, i, n));
}
