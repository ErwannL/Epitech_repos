/*
** EPITECH PROJECT, 2021
** star
** File description:
** function that displays a star, based on its given size
*/

int my_putstr(char const *str);

int make_conne2(int nbr_space_before)
{
    while (nbr_space_before > 0) {
        my_putstr(" ");
        nbr_space_before--;
    }
    my_putstr("*");
}

void make_conne(unsigned int size)
{
    int nbr_ligne = size - 1;
    int nbr_space_before = (3 * size) - 2;
    int increment_space_before = 1;
    int space_in_conne = 1;

    while (nbr_ligne >= 1) {
        nbr_space_before = make_conne2(nbr_space_before);
        nbr_ligne--;
        nbr_space_before = (3 * size) - 2 - increment_space_before;
        increment_space_before++;
        for (int i = 0; i < space_in_conne; i++) {
            my_putstr(" ");
        }
    space_in_conne += 2;
    my_putstr("*\n");
    }
}

int make_conne_revers2(int nbr_space_before, int size)
{
    while (nbr_space_before < (3 * size)) {
        my_putstr(" ");
        nbr_space_before++;
    }
    my_putstr("*");
}

void make_conne_revers(unsigned int size)
{
    int nbr_ligne = size - 1;
    int nbr_space_before = size;
    int increment_space_before = 1;
    int space_in_conne = (2 * size) - 2;

    while (nbr_ligne >= 1) {
        nbr_space_before = make_conne_revers2(nbr_space_before, size);
        nbr_ligne--;
        nbr_space_before = size - 2 + increment_space_before;
        increment_space_before--;
        for (int i = 1; i < space_in_conne; i++) {
            my_putstr(" ");
        }
    space_in_conne -= 2;
    my_putstr("*\n");
    }
}
