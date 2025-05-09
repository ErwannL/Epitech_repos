/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main file
*/

#include "my_rpg.h"

int handle_events(win_t *win)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->event.type == sfEvtClosed || (buttons_events(win) == -1)
                                    || sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(win->window);
        }
    }
    return 0;
}

void my_rpg(void)
{
    win_t *win = (win_t *)malloc(sizeof(win_t));
    win->player = (player_t *)malloc(sizeof(player_t));

    srand(time(NULL));
    create_things(win);
    for (; sfRenderWindow_isOpen(win->window);) {
        if (handle_events(win) == -1)
            break;
        if (sfClock_getElapsedTime(win->time).microseconds > 100000) {
            refresh_all(win);
        }
        win = resize_window(win);
    }
    free_all(win);
}

void print_h(void)
{
    my_putstr("Finite RPG created with CSFML.\n");
    my_putstr("\n   USAGE\n");
    my_putstr("./my_rpg or ./my_rpg -h or ./my_rpg --help\n");
    my_putstr("\n   GOAL OF THE GAME\n");
    my_putstr("The player must resolve all his quest, explore the world and ");
    my_putstr("meet all pokemon\n");
    my_putstr("\n   OPTIONS\n");
    my_putstr("-h     Print the usage and quit.\n");
    my_putstr("\n   USER INTERACTIONS\n");
    my_putstr("MOUSE CLICK        Quit the homepage menu\n");
    my_putstr("ESCAPE             Quit the game from anywhere.\n");
    my_putstr("A                  Click button in menu.\n");
    my_putstr("B                  Click on some button when it's written\n");
    my_putstr("NUMBER 1 TO 9      Customize the player\n");
    my_putstr("ARROW              Move in menu & move the player\n");
    my_putstr("ENTER              Go from game to pause menu\n");
    my_putstr("Q                  Quit Some Menu or page\n");
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0
        || my_strcmp(argv[1], "--help") == 0) {
            print_h();
            return 0;
        } else {
            MY_PUTSTR("[my_rpg]: bad flag given.\nretry with -h\n");
            return 84;
        }
    }
    if (argc > 2) {
        return 84;
    }
    my_rpg();
    return 0;
}
