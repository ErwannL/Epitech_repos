/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-erwann.laplante
** File description:
** str_nbr
*/

#include "../include/my.h"

char *nbr_str_next(int nbr, char *str)
{
    str[0] = (nbr / 1000) + 48;
    str[1] = ((nbr / 100) % 10) + 48;
    str[2] = ((nbr / 10) % 10) + 48;
    str[3] = (nbr % 10) + 48;
    str[4] = '\0';
    return str;
}

char *nbr_str_bis(int nbr, char *str)
{
    if (nbr <= 999 && nbr > 99) {
        str[0] = (nbr / 100) + 48;
        str[1] = ((nbr / 10) % 10)+ 48;
        str[2] = (nbr % 10) + 48;
        str[3] = '\0';
    }else if (nbr > 999)
        str = nbr_str_next(nbr, str);
    return str;
}

char *nbr_str(int nbr)
{
    char *str = malloc(sizeof(char) * 5);

    if (nbr <= 9) {
        str[0] = nbr + 48;
        str[1] = '\0';
    } else if (nbr <= 99 && nbr > 9) {
        str[0] = (nbr / 10) + 48;
        str[1] = (nbr % 10) + 48;
        str[2] = '\0';
    } else
        str = nbr_str_bis(nbr, str);
    return str;
}
