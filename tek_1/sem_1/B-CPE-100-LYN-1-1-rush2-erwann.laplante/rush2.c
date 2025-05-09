/*
** EPITECH PROJECT, 2021
** Step 2
** File description:
**  Counting the number of occurences of several letters
*/

#include "lib/my/my.h"

int is_alpha(char *s)
{
    int longueur = 0;
    int i = 0;

    while (s[i] != '\0') {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            longueur++;
        i++;
    }
    return (longueur);
}

int print_pourcent(int len_str, int nb_lettre)
{
    float a = ((float)nb_lettre / len_str) * 100;
    int b = a * 100;
    int c = b / 100;
    int d = b % 100;

    my_putstr(" (");
    if (c < 10)
        my_put_nbr(0);
    my_put_nbr(c);
    my_putchar('.');
    my_put_nbr(d);
    if (d < 10)
        my_put_nbr(0);
    my_putstr("%)");
    return (0);
}

int number_letter(char *str, char letter)
{
    int i = 0;
    int nb_lettre = 0;
    int len_str;

    len_str = is_alpha(str);
    while (str[i] != '\0') {
        if (str[i] == my_strlowcase(letter) || str[i] == my_strupcase(letter))
            nb_lettre += 1;
        i += 1;
    }
    my_putchar(letter);
    my_putchar(':');
    my_put_nbr(nb_lettre);
    print_pourcent(len_str, nb_lettre);
    my_putchar('\n');
    return (0);
}

int occurences_of_letter(int ac, char **av)
{
    int i = 2;

    while (i < ac) {
        number_letter(av[1], av[i][0]);
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac > 1 && my_strlen(av[1]) > 0) {
        occurences_of_letter(ac, av);
        return (0);
    }
    return (84);
}
