/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-erwann.laplante
** File description:
** SFML
*/

#include "SFML.hpp"

extern "C" std::shared_ptr<SFML> init(void)
{
    return std::make_shared<SFML>();
}

SFML::SFML()
{
}

SFML::~SFML()
{
}

Arcade::Type SFML::getTypeClass (void)
{
    return this->what;
}

sf::Text createText(const char *str, unsigned int size, const sf::Font& font, const sf::Color& color, float x, float y)
{
    sf::Text text;
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setPosition(x, y);
    return text;
}

sf::Text updateText(sf::Text &text, const char *str)
{
    text.setString(str);
    return text;
}

void SFML::displayMenu(void)
{
    int bit = 0;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Crazy Game");

    window.setFramerateLimit(144);

    sf::Texture texture;
    texture.loadFromFile("assets/menu_background.jpg");

    sf::Sprite sprite;
    sprite.setTexture(texture);

    float scaleX = (float) window.getSize().x / texture.getSize().x;
    float scaleY = (float) window.getSize().y / texture.getSize().y;
    sprite.setScale(scaleX, scaleY);

    sf::Font font;
    font.loadFromFile("assets/arial.ttf");

    std::string name = "Bob";
    auto text = createText("name :", 24, font, sf::Color::White, 10.f, 10.f);
    auto text_name = createText(name.c_str(), 24, font, sf::Color::White, 100.f, 10.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
                window.close();
            } else if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::A) {
                    if (name.length() < 10)
                    name.push_back('a');
                    break;
                } else if (event.key.code == sf::Keyboard::B) {
                    if (name.length() < 10)
                    name.push_back('b');
                    break;
                } else if (event.key.code == sf::Keyboard::C) {
                    if (name.length() < 10)
                    name.push_back('c');
                    break;
                } else if (event.key.code == sf::Keyboard::D) {
                    if (name.length() < 10)
                    name.push_back('d');
                    break;
                } else if (event.key.code == sf::Keyboard::E) {
                    if (name.length() < 10)
                    name.push_back('e');
                    break;
                } else if (event.key.code == sf::Keyboard::F) {
                    if (name.length() < 10)
                    name.push_back('f');
                    break;
                } else if (event.key.code == sf::Keyboard::G) {
                    if (name.length() < 10)
                    name.push_back('g');
                    break;
                } else if (event.key.code == sf::Keyboard::H) {
                    if (name.length() < 10)
                    name.push_back('h');
                    break;
                } else if (event.key.code == sf::Keyboard::I) {
                    if (name.length() < 10)
                    name.push_back('i');
                    break;
                } else if (event.key.code == sf::Keyboard::J) {
                    if (name.length() < 10)
                    name.push_back('j');
                    break;
                } else if (event.key.code == sf::Keyboard::K) {
                    if (name.length() < 10)
                    name.push_back('k');
                    break;
                } else if (event.key.code == sf::Keyboard::L) {
                    if (name.length() < 10)
                    name.push_back('l');
                    break;
                } else if (event.key.code == sf::Keyboard::M) {
                    if (name.length() < 10)
                    name.push_back('m');
                    break;
                } else if (event.key.code == sf::Keyboard::N) {
                    if (name.length() < 10)
                    name.push_back('n');
                    break;
                } else if (event.key.code == sf::Keyboard::O) {
                    if (name.length() < 10)
                    name.push_back('o');
                    break;
                } else if (event.key.code == sf::Keyboard::P) {
                    if (name.length() < 10)
                    name.push_back('p');
                    break;
                } else if (event.key.code == sf::Keyboard::Q) {
                    if (name.length() < 10)
                    name.push_back('q');
                    break;
                } else if (event.key.code == sf::Keyboard::R) {
                    if (name.length() < 10)
                    name.push_back('r');
                    break;
                } else if (event.key.code == sf::Keyboard::S) {
                    if (name.length() < 10)
                    name.push_back('s');
                    break;
                } else if (event.key.code == sf::Keyboard::T) {
                    if (name.length() < 10)
                    name.push_back('t');
                    break;
                } else if (event.key.code == sf::Keyboard::U) {
                    if (name.length() < 10)
                    name.push_back('u');
                    break;
                } else if (event.key.code == sf::Keyboard::V) {
                    if (name.length() < 10)
                    name.push_back('v');
                    break;
                } else if (event.key.code == sf::Keyboard::W) {
                    if (name.length() < 10)
                    name.push_back('w');
                    break;
                } else if (event.key.code == sf::Keyboard::X) {
                    if (name.length() < 10)
                    name.push_back('x');
                    break;
                } else if (event.key.code == sf::Keyboard::Y) {
                    if (name.length() < 10)
                    name.push_back('y');
                    break;
                } else if (event.key.code == sf::Keyboard::Z) {
                    if (name.length() < 10)
                        name.push_back('z');
                    break;
                } else if (event.key.code == sf::Keyboard::Space) {
                    if (name.length() < 10)
                        name.push_back(' ');
                    break;
                } else if (event.key.code == sf::Keyboard::BackSpace) {
                    if (name.empty() == false)
                        name.pop_back();
                    break;
                } else if (event.key.code == sf::Keyboard::Right) {
                    bit = 1;
                    window.close();
                    changing(bit);
                    return;
                } else if (event.key.code == sf::Keyboard::Left) {
                    bit = 2;
                    window.close();
                    changing(bit);
                    return;
                }
            }
        }
        text_name = updateText(text_name, name.c_str());

        if (window.getSize().x < 800)
            window.setSize(sf::Vector2u(800, window.getSize().y));

        if (window.getSize().y < 600)
            window.setSize(sf::Vector2u(window.getSize().y, 600));

        window.clear();
        window.draw(sprite);

        window.draw(text);
        window.draw(text_name);

        window.display();
    }
}

int SFML::changing(int bit)
{
    std::string libstring;
    if (bit == 1)
        libstring = "lib/arcade_ncurses.so";
    if (bit == 2)
        libstring = "lib/arcade_sdl2.so";
    void *handle = dlopen(libstring.c_str(), RTLD_LAZY);
    char *error = dlerror();
    if (!handle || error != NULL) {
        std::cerr << "arcade_ncurses.so" << " => Unknown lib" << std::endl << error << std::endl;
        return 84;
    }

    std::shared_ptr<Arcade::Graphicals> (*lib)() = (std::shared_ptr<Arcade::Graphicals>(*)())dlsym(handle, "init");

    if (!lib || lib()->getTypeClass() != Arcade::Type::Graphical) {
        std::cerr << "arcade_ncurses.so" << " is not a graphical library" << std::endl;
        return 84;
    }

    lib()->displayMenu();
    return 0;
}
