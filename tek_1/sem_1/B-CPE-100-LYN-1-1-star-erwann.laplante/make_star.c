/*
** EPITECH PROJECT, 2021
** star
** File description:
** function that displays a star, based on its given size
*/

int my_putstr(char const *str);

void make_first_last_line(unsigned int size)
{
    int number_space = (3 * size) - 1;

    while (number_space> 0) {
        my_putstr(" ");
        number_space--;
    }
    my_putstr("*\n");
}

void make_bra(unsigned int size)
{
    int nbr_star = (2 * size) + 1;

    for (int i = 0; i < nbr_star; i++) {
        my_putstr("*");
    }
    for (int i = 0; i < (2 * size) - 3 ; i++) {
        my_putstr(" ");
    }
    for (int i = 0; i < nbr_star; i++) {
        my_putstr("*");
    }
    my_putstr("\n");
}

void make_cor_one(unsigned int size)
{
    int nbr_space = (5 * size) - 2;
    int nbr_space_before = 1;

    while (nbr_space > (size * 3)) {
        for(int i = 0; i < nbr_space_before; i++) {
            my_putstr(" ");
        }
        nbr_space_before++;
        my_putstr("*");
        for (int i = 0; i < nbr_space  + size - 3; i++) {
            my_putstr(" ");
        }
    my_putstr("*\n");
    nbr_space -= 2;
    }
}

void make_cor_two(unsigned int size)
{
    int nbr_space = (size * 3);
    int nbr_space_before = size;
    
    while (nbr_space <= (5 * size) - 2) {
        for(int i = nbr_space_before; i > 0; i--) {
            my_putstr(" ");
        }
        nbr_space_before --;
        my_putstr("*");
        for (int i = 0; i < nbr_space + size - 3; i++) {
            my_putstr(" ");
        }
    my_putstr("*\n");
    nbr_space += 2;
    }
}
