/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-erwann.laplante
** File description:
** SDL2
*/

#include "SDL2.hpp"

extern "C" std::shared_ptr<SDL2> init(void)
{
    return std::make_shared<SDL2>();
}

SDL2::SDL2()
{
}

SDL2::~SDL2()
{
}

Arcade::Type SDL2::getTypeClass (void)
{
    return this->what;
}

SDL_Texture* SDL2::createText(SDL_Renderer* renderer, const char *str, TTF_Font* font, SDL_Color color, int x, int y, SDL_Rect& rect)
{
    SDL_Surface* surface = TTF_RenderText_Solid(font, str, color);
    if (surface == NULL)
    {
        printf("text creation failed: %s\n", TTF_GetError());
        exit(84);
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    rect.x = x;
    rect.y = y;
    rect.w = surface->w;
    rect.h = surface->h;

    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* SDL2::updateText(SDL_Renderer* renderer, SDL_Texture* texture, const char *str, TTF_Font* font, SDL_Color color, int x, int y, SDL_Rect& rect)
{
    SDL_Surface* surface = TTF_RenderText_Solid(font, str, color);

    if (surface == NULL)
    {
        printf("text creation failed: %s\n", TTF_GetError());
        exit(84);
    }

    SDL_DestroyTexture(texture);

    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, surface);

    rect.x = x;
    rect.y = y;
    rect.w = surface->w;
    rect.h = surface->h;

    SDL_FreeSurface(surface);

    return newTexture;
}

void SDL2::createWindow(void)
{
    int bit = 0;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Crazy Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Init();
    font = TTF_OpenFont("assets/arial.ttf", 24);
    white = { 255, 255, 255 };
    name = "Bob";
}

void SDL2::createBackground(void)
{
    imageSurface = IMG_Load("assets/menu_background.jpg");
    imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
}

void SDL2::setTexte(void)
{
    text = createText(renderer, "name :", font, white, 10, 10, rect);
    text_name = createText(renderer, name.c_str(), font, white, 100, 10, rect_name);
}

    std::string name = "Bob";

    SDL_Color white = { 255, 255, 255 };

    SDL_Rect rect;
    SDL_Texture* text = createText(renderer, "name :", font, white, 10, 10, rect);

    SDL_Rect rectname;
    SDL_Texture* textname = createText(renderer, name.c_str(), font, white, 100, 10, rectname);

    while (true) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                return;
            } else if (event.type == SDL_KEYUP) {
                if (event.key.keysym.sym == SDLK_a) {
                    if (name.length() < 10)
                        name.push_back('a');
                    break;
                } else if (event.key.keysym.sym == SDLK_b) {
                    if (name.length() < 10)
                        name.push_back('b');
                    break;
                } else if (event.key.keysym.sym == SDLK_c) {
                    if (name.length() < 10)
                        name.push_back('c');
                    break;
                } else if (event.key.keysym.sym == SDLK_d) {
                    if (name.length() < 10)
                        name.push_back('d');
                    break;
                } else if (event.key.keysym.sym == SDLK_e) {
                    if (name.length() < 10)
                        name.push_back('e');
                    break;
                } else if (event.key.keysym.sym == SDLK_f) {
                    if (name.length() < 10)
                        name.push_back('f');
                    break;
                } else if (event.key.keysym.sym == SDLK_g) {
                    if (name.length() < 10)
                        name.push_back('g');
                    break;
                } else if (event.key.keysym.sym == SDLK_h) {
                    if (name.length() < 10)
                        name.push_back('h');
                    break;
                } else if (event.key.keysym.sym == SDLK_i) {
                    if (name.length() < 10)
                        name.push_back('i');
                    break;
                } else if (event.key.keysym.sym == SDLK_j) {
                    if (name.length() < 10)
                        name.push_back('j');
                    break;
                } else if (event.key.keysym.sym == SDLK_k) {
                    if (name.length() < 10)
                        name.push_back('k');
                    break;
                } else if (event.key.keysym.sym == SDLK_l) {
                    if (name.length() < 10)
                        name.push_back('l');
                    break;
                } else if (event.key.keysym.sym == SDLK_m) {
                    if (name.length() < 10)
                        name.push_back('m');
                    break;
                } else if (event.key.keysym.sym == SDLK_n) {
                    if (name.length() < 10)
                        name.push_back('n');
                    break;
                } else if (event.key.keysym.sym == SDLK_o) {
                    if (name.length() < 10)
                        name.push_back('o');
                    break;
                } else if (event.key.keysym.sym == SDLK_p) {
                    if (name.length() < 10)
                        name.push_back('p');
                    break;
                } else if (event.key.keysym.sym == SDLK_q) {
                    if (name.length() < 10)
                        name.push_back('q');
                    break;
                } else if (event.key.keysym.sym == SDLK_r) {
                    if (name.length() < 10)
                        name.push_back('r');
                    break;
                } else if (event.key.keysym.sym == SDLK_s) {
                    if (name.length() < 10)
                        name.push_back('s');
                    break;
                } else if (event.key.keysym.sym == SDLK_t) {
                    if (name.length() < 10)
                        name.push_back('t');
                    break;
                } else if (event.key.keysym.sym == SDLK_u) {
                    if (name.length() < 10)
                        name.push_back('u');
                    break;
                } else if (event.key.keysym.sym == SDLK_v) {
                    if (name.length() < 10)
                        name.push_back('v');
                    break;
                } else if (event.key.keysym.sym == SDLK_w) {
                    if (name.length() < 10)
                        name.push_back('w');
                    break;
                } else if (event.key.keysym.sym == SDLK_x) {
                    if (name.length() < 10)
                        name.push_back('x');
                    break;
                } else if (event.key.keysym.sym == SDLK_a) {
                    if (name.length() < 10)
                        name.push_back('a');
                    break;
                } else if (event.key.keysym.sym == SDLK_y) {
                    if (name.length() < 10)
                        name.push_back('y');
                    break;
                } else if (event.key.keysym.sym == SDLK_z) {
                    if (name.length() < 10)
                        name.push_back('z');
                    break;
                } else if (event.key.keysym.sym == SDLK_SPACE) {
                    if (name.length() < 10)
                        name.push_back(' ');
                    break;
                } else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                    if (name.empty() == false)
                        name.pop_back();
                    break;
                } else if (event.key.keysym.sym == SDLK_RIGHT) {
                    bit = 1;
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    changing(bit);
                    return;
                } else if (event.key.keysym.sym == SDLK_LEFT) {
                    bit = 2;
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    changing(bit);
                    return;
                }
            }
        }
        if (bit == 0) {
            if (name != "")
                textname = updateText(renderer, textname, name.c_str(), font, white, 100, 10, rectname);

            int w, h;
            SDL_GetWindowSize(window, &w, &h);
            if (w < 800)
                SDL_SetWindowSize(window, 800, h);
            if (h < 600)
                SDL_SetWindowSize(window, w, 600);

            SDL_RenderClear(renderer);

            SDL_Rect imageRect = { 0, 0, 800, 600 };

            SDL_RenderCopy(renderer, imageTexture, NULL, &imageRect);

            SDL_RenderCopy(renderer, text, NULL, &rect);

            if (name != "")
                SDL_RenderCopy(renderer, textname, NULL, &rectname);

            SDL_RenderPresent(renderer);
        }
    }
}

int SDL2::changing(int bit)
{
    std::string libstring;
    if (bit == 1)
        libstring = "lib/arcade_sfml.so";
    if (bit == 2)
        libstring = "lib/arcade_ncurses.so";
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