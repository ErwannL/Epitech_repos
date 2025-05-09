/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-erwann.laplante
** File description:
** NCurses
*/

#ifndef NCURSES_HPP_
    #define NCURSES_HPP_

    #include "Graphicals.hpp"

    #include <ncurses.h>

    class NCurses : virtual public Arcade::Graphicals {
        public:
            NCurses();
            ~NCurses();

            Arcade::Type getTypeClass (void);
            void displayMenu(void);
            int changing(int bit);
                        /* ============= Library ============= */
            void clear(void){};
            void refresh(void){};
            void update(std::map<std::string, Sprite> &){};

            /* ============= Window ============= */
            void createWin(void){};
            void deleteWin(void){};

            bool manageEvent(void){};
            void checkCollide(std::map<std::string, Sprite> &){};

            void addSprite(Sprite &){};
            void drawSprites(std::map<std::string, Sprite> &){};
            std::pair<std::string, bool> getKey(void){};
            std::pair<int, int>getWindowBorders(void){};

            /* ============= Extra ============= */
            std::string getName(void) const{};


        protected:
            Arcade::Type what = Arcade::Type::Graphical;
            WINDOW* window;
            std::string name;
            int ch;
            bool open = true;
    };

    extern "C" std::shared_ptr<NCurses> init(void);

#endif /* !NCURSES_HPP_ */
