/*
** EPITECH PROJECT, 2023
** IMonitorModule.hpp
** File description:
** no ideas
*/

#ifndef IMONITORMODULE_HPP_
    #define IMONITORMODULE_HPP_
    #include <cstring>
    #include <iostream>
    #include <ncurses.h>

    class IMonitorModule {
        private:
            int addSpace(const char *str) { return (this->_width / 2) - (strlen(str) / 2); }

        public:
            int _x = 0;
            int _y = 0;
            int _space = 1;
            int _width = 0;
            int _limit = 0;
            std::string _name = "";

            ~IMonitorModule(void) {};

            IMonitorModule(int x, int y, int width, int limit)
                            : _x(x), _y(y), _width(width), _limit(limit) {};

            void printTitle(const char *str)
            {
                mvhline(this->_y, this->_x, ACS_ULCORNER, 1);
                mvhline(this->_y, this->_x + this->_width, ACS_URCORNER, 1);
                mvhline(this->_y, this->_x + 1, ACS_HLINE, addSpace(str));
                mvhline(this->_y, this->_x + addSpace(str), ACS_HLINE, addSpace(str));
                mvprintw(this->_y, this->_x + 2 * (addSpace(str)), "%s", str);
            }
            void printStr(const char *what)
            {
                if (this->_space >= this->_limit) { this->_space = 1; }
                mvhline(this->_y + this->_space, this->_x, ACS_VLINE, 1);
                mvprintw(this->_y + this->_space, this->_x + addSpace(what), "%s", what);
                mvhline(this->_y + this->_space, this->_x + this->_width, ACS_VLINE, 1);
                this->_space++;
            }

            void printBottom(void)
            {
                mvhline(this->_y + this->_limit, this->_x + 1, ACS_HLINE, this->_width);
                mvhline(this->_y + this->_limit, this->_x, ACS_LLCORNER, 1);
                mvhline(this->_y + this->_limit, this->_x + this->_width, ACS_LRCORNER, 1);
            }

            void display(void) {}
            void refresh(void) {}
    };

#endif /* !IMONITORMODULE_HPP_ */
