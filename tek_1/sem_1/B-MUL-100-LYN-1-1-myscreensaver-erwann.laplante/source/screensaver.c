/*
** EPITECH PROJECT, 2021
** graphical_programing
** File description:
** csfml_initialisation
*/

#include "../includes/my.h"

initialisation_t declaration_var(initialisation_t init)
{
    1 == 1 ? init.s[0] = '1', init.s[1] = '2', init.s[2] = '3': 0;
    init.s[3] = '4';
    init.s[4] = '5';
    init.s[5] = '6';
    init.s[6] = '7';
    init.s[7] = '8';
    init.s[8] = '9';
    init.s[9] = '\0';
    init.sc[0] = screen_saver1_1;
    init.sc[1] = screen_saver2_1;
    init.sc[2] = screen_saver3_1;
    init.sc[3] = screen_saver4_1;
    init.sc[4] = screen_saver5_1;
    init.sc[5] = screen_saver6_1;
    init.sc[6] = screen_saver7_1;
    init.sc[7] = screen_saver8_1;
    init.sc[8] = screen_saver9_1;
    init.i = 0;
    init.r = 84;
    return (init);
}

void case_null(void)
{
    my_putstr("./my_screensaver: bad arguments: 0 given but 1 is require");
    my_putstr("d\nretry with -h\n");
}

void case_h(void)
{
    my_putstr("animation rendering in a CSFML window.\n\nUSAGE\n./my_screens");
    my_putstr("aver [OPTIONS] animation_id\nanimation_id ID of the animation");
    my_putstr(" to process (between 1 and 9).\n\nOPTIONS\n-d print the descr");
    my_putstr("iption of all the animations and quit.\n-h print the usage an");
    my_putstr("d quit.\n\nUSER INTERACTIONS\nLEFT_ARROW switch to the previo");
    my_putstr("us animation.\nRIGHT_ARROW switch to the next animation.\n");
}

void case_d(void)
{
    my_putstr("1: Draw the diagonal of the window in blue then in red and st");
    my_putstr("art again.\n2: Draw larger and larger blue squares diagonally");
    my_putstr(" then do the reverse by drawing smaller and smaller red squar");
    my_putstr("es and start again.\n3: Create a black and white checkerboard");
    my_putstr(", erase it and start again.\n4: Create a multicolored checker");
    my_putstr("board, erase it and start again.\n5: Create random colored do");
    my_putstr("ts at random place on the screen.\n6: Create a randomly color");
    my_putstr("ed empty square at a random location on the screen with a ran");
    my_putstr("dom size.\n7: Create a square with random coordinates and mak");
    my_putstr("e it grow with random colors until it touches an edge of the ");
    my_putstr("window then start again.\n8: Draw a circle of a random color ");
    my_putstr("with a minimum transparency in the middle of the window and m");
    my_putstr("ake it bigger by increasing its transparency until it reaches");
    my_putstr(" the maximum then do the same thing backwards and start again");
    my_putstr(".\n9: Draw a thick line between between two random edges and ");
    my_putstr("bounce it, the color of the line goes from black to white the");
    my_putstr("n white to black and start again.\n");
}

int main(int ac, char **av)
{
    initialisation_t i;

    i = declaration_var(i);
    if (ac == 1) {
        case_null();
        return (84);
    }
    if (ac == 2) {
        ((av[1][0] == '-' && av[1][1] == 'h') ? case_h(), i.r = 0 : 0);
        ((av[1][0] == '-' && av[1][1] == 'd') ? case_d(), i.r = 0 : 0);
        if (av[1][0] == '-' && i.r != 0) {
            my_putstr("./my_screensaver: bad options !\nretry with -h\n");
            return (84);
        }
        i = help_main(i, av);
        if (i.r == 0)
            return (0);
    }
    my_putstr("./my_screensaver: bad arguments !\nretry with -h\n");
    return (84);
}
