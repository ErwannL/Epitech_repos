/*
** EPITECH PROJECT, 2021
** Rush-1
** File description:
** The function display a square on the screen
*/

void ligne_x_un(int x, int y)
{
    my_putstr("B");
    for (int i = 0; i < x - 2; i++) {
        my_putstr("B");
    }
    my_putstr("B\n");
}

void ligne_y_un(int x, int y)
{
    my_putstr("B\n");
    for (int i = 0; i < y - 2; i++) {
        my_putstr("B\n");
    }
    my_putstr("B\n");
}

void ligne_x_d(int x, int y)
{
    my_putstr("A");
    for (int i = 0; i < x - 2; i++) {
        my_putstr("B");
    }
    my_putstr("C");
    my_putstr("\n");
}

void ligne_x_f(int x, int y)
{
    my_putstr("A");
    for (int i = 0; i < x - 2; i++) {
        my_putstr("B");
    }
    my_putstr("C\n");
}
