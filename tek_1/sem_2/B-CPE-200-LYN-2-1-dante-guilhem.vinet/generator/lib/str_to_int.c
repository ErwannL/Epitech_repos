/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-dante-guilhem.vinet
** File description:
** str_to_int
*/

int my_str_to_int(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        nb = (10 * nb) + (str[i] - 48);
    }
    return nb;
}
