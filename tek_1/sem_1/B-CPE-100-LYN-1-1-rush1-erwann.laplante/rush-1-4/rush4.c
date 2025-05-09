/*
** EPITECH PROJECT, 2021
** Rush-1
** File description:
** The function display a square on the screen
*/

char test_nega(int x, int y)
{
    if (x < 0 || y < 0) {
        write(2, "Invalid size\n", 13);
        return (1);
    } else {
        return (0);
    }
}

void print_else(int x, int y)
{
    ligne_x_d(x, y);
    for (int i = 0; i < y - 2; i++) {
        my_putstr("B");
        for (int i = 0; i < x - 2; i++) {
            my_putstr(" ");
        }
        my_putstr("B\n");
    }
    ligne_x_f(x, y);
}

void rush(int x, int y)
{
    int test = test_nega(x, y);

    if (test == 1) {
        x = 0;
        y = 0;
    }
    if (x == 1 && y == 1) {
        if (y == 1)
            ligne_x_un(x, y);
        else if (x == 1)
            ligne_y_un(x, y);
        else 
            my_putstr("B\n");
    }
    else if (x > 1 && y > 1 )
        print_else(x, y);
}
