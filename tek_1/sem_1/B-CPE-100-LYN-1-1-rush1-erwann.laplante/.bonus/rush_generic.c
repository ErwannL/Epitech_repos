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
        my_putstr("|");
        for (int i = 0; i < x - 2; i++) {
            my_putstr(" ");
        }
        my_putstr("|\n");
    }
    ligne_x_f(x, y);
}

void rush_generic(int x, int y, char *solo)
{
    int test = test_nega(x, y);

    if (test == 1) {
        x = 0;
        y = 0;
    }
    if (x == 1 || y == 1) {
        if (y == 1 && x != 1)
            ligne_x_un(x, y);
        else if (x == 1 && y != 1)
            ligne_y_un(x, y);
        else {
            my_putstr(solo);
            my_putstr("\n");
        }
    }
    if (x > 1 && y > 1 )
        print_else(x, y);
}

void rush(int x, int y, char *solo)
{
    rush_generic(x, y, solo);
}
int main(void){
    rush(1, 4, strdup("solo"));
    return(0);
}