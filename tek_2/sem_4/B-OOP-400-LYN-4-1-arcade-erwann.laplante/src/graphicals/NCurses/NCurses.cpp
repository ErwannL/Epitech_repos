/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-erwann.laplante
** File description:
** NCurses
*/

#include "NCurses.hpp"

extern "C" std::shared_ptr<NCurses> init(void)
{
    return std::make_shared<NCurses>();
}

NCurses::NCurses()
{
}

NCurses::~NCurses()
{
}

Arcade::Type NCurses::getTypeClass (void)
{
    return this->what;
}

WINDOW* NCurses::createText(const char* str, WINDOW* win, int x, int y)
{
    mvprintw(x, y, "%s", str);
    wrefresh(win);
    return win;
}

WINDOW* NCurses::updateText(WINDOW* win, const char* str, int x, int y)
{
    mvprintw(x, y, "%s", str);
    wrefresh(win);
    return win;
}

void NCurses::createWindow(void)
{
    int bit = 0;
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    window = newwin(24, 80, 0, 0);
    name = "Bob";
}

void NCurses::createBackground(void)
{
    box(window, 0, 0);
    wrefresh(window);
}

void NCurses::setTexte(void)
{
    window = createText("name :", window, 1, 1);
    window = createText(name.c_str(), window, 1, 10);
}

    int ch;
    while ((ch = getch()) != 27) {
        switch (ch) {
            case 'a':
                if (name.length() < 10)
                    name.push_back('a');
                break;
            case 'b':
                if (name.length() < 10)
                    name.push_back('b');
                break;
            case 'c':
                if (name.length() < 10)
                    name.push_back('c');
                break;
            case 'd':
                if (name.length() < 10)
                    name.push_back('d');
                break;
            case 'e':
                if (name.length() < 10)
                    name.push_back('e');
                break;
            case 'f':
                if (name.length() < 10)
                    name.push_back('f');
                break;
            case 'g':
                if (name.length() < 10)
                    name.push_back('g');
                break;
            case 'h':
                if (name.length() < 10)
                    name.push_back('h');
                break;
            case 'i':
                if (name.length() < 10)
                    name.push_back('i');
                break;
            case 'j':
                if (name.length() < 10)
                    name.push_back('j');
                break;
            case 'k':
                if (name.length() < 10)
                    name.push_back('k');
                break;
            case 'l':
                if (name.length() < 10)
                    name.push_back('l');
                break;
            case 'm':
                if (name.length() < 10)
                    name.push_back('m');
                break;
            case 'n':
                if (name.length() < 10)
                    name.push_back('n');
                break;
            case 'o':
                if (name.length() < 10)
                    name.push_back('o');
                break;
            case 'p':
                if (name.length() < 10)
                    name.push_back('p');
                break;
            case 'q':
                if (name.length() < 10)
                    name.push_back('q');
                break;
            case 'r':
                if (name.length() < 10)
                    name.push_back('r');
                break;
            case 's':
                if (name.length() < 10)
                    name.push_back('s');
                break;
            case 't':
                if (name.length() < 10)
                    name.push_back('t');
                break;
            case 'u':
                if (name.length() < 10)
                    name.push_back('u');
                break;
            case 'v':
                if (name.length() < 10)
                    name.push_back('v');
                break;
            case 'w':
                if (name.length() < 10)
                    name.push_back('w');
                break;
            case 'x':
                if (name.length() < 10)
                    name.push_back('x');
                break;
            case 'y':
                if (name.length() < 10)
                    name.push_back('y');
                break;
            case 'z':
                if (name.length() < 10)
                    name.push_back('z');
                break;
            case ' ':
                if (name.length() < 10)
                    name.push_back(' ');
                break;
            case KEY_BACKSPACE:
                if (!name.empty())
                    name.pop_back();
                break;
            case '1':
                bit = 1;
                delwin(window);
                endwin();
                changing(bit);
                return;
            case '2':
                bit = 2;
                delwin(window);
                endwin();
                changing(bit);
                break;
        }
        werase(window);
        window = updateText(window, "name : ", 1, 1);
        window = updateText(window, name.c_str(), 1, 10);

    }        
    delwin(window);
    endwin();
    return;
}

int NCurses::changing(int bit)
{
    std::string libstring;
    if (bit == 1)
        libstring = "lib/arcade_sfml.so";
    if (bit == 2)
        libstring = "lib/arcade_sdl2.so";
    void *handle = dlopen(libstring.c_str(), RTLD_LAZY);
    char *error = dlerror();
    if (!handle || error != NULL) {
        std::cerr << libstring << " => Unknown lib" << std::endl << error << std::endl;
        return 84;
    }

    std::shared_ptr<Arcade::Graphicals> (*lib)() = (std::shared_ptr<Arcade::Graphicals>(*)())dlsym(handle, "init");

    if (!lib || lib()->getTypeClass() != Arcade::Type::Graphical) {
        std::cerr << libstring << " is not a graphical library" << std::endl;
        return 84;
    }

    lib()->displayMenu();
    return 0;
}