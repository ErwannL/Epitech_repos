/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-erwann.laplante
** File description:
** SDL2
*/

#ifndef SDL2_HPP_
    #define SDL2_HPP_

    #include "Graphicals.hpp"
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_ttf.h>

    class SDL2 : virtual public Arcade::Graphicals {
        public:
            SDL2();
            ~SDL2();

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
            SDL_Window* window;
            SDL_Renderer* renderer;
            TTF_Font* font;
            SDL_Color white;
            std::string name;
            SDL_Surface* imageSurface;
            SDL_Texture* imageTexture;
            SDL_Rect rect;
            SDL_Texture* text;
            SDL_Rect rect_name;
            SDL_Texture* text_name;
            bool open = true;
    };

    extern "C" std::shared_ptr<SDL2> init(void);

#endif /* !SDL2_HPP_ */
