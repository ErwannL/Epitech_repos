/*
** EPITECH PROJECT, 2021
** Rush-1
** File description:
** The function display a square on the screen
*/

void ligne_x_un(int x, int y)
{
    my_putstr("o");
    for (int i = 0; i < x - 2; i++) {
        my_putstr("-");
    }
    my_putstr("o\n");
}

void ligne_y_un(int x, int y)
{
    my_putstr("o\n");
    for (int i = 0; i < y - 2; i++) {
        my_putstr("|\n");
    }
    my_putstr("o\n");
}

void ligne_x_d(int x, int y)
{
    my_putstr("o");
    for (int i = 0; i < x - 2; i++) {
        my_putstr("-");
    }
    my_putstr("o");
    my_putstr("\n");
}

void ligne_x_f(int x, int y)
{
    my_putstr("o");
    for (int i = 0; i < x - 2; i++) {
        my_putstr("-");
    }
    my_putstr("o\n");
}
