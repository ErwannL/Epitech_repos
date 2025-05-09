/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu()
{
}

Menu::~Menu()
{

}

void Menu::init(sf::RenderWindow &window, std::shared_ptr<Client> &)
{
    sf::Vector2u windowSize = window.getSize();

    if (!_font.loadFromFile("gui/assets/Minecraft.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
    _textureMap["AllAssets"].loadFromFile("gui/assets/MiniWorldSprites/AllAssetsPreview.png");

    sf::Vector2f middlePos = sf::Vector2f(windowSize.x / 2 - 100, windowSize.y / 2 - 25);
    Button play = Button(sf::RectangleShape(sf::Vector2f(200, 50)), middlePos, sf::Text("Play", _font, 20), std::string("Play"));
    Button setting = Button(sf::RectangleShape(sf::Vector2f(200, 50)), sf::Vector2f(middlePos.x, middlePos.y + 75), sf::Text("Settings", _font, 20), std::string("Settings"));
    Button title = Button(sf::RectangleShape(sf::Vector2f(200, 50)), sf::Vector2f(middlePos.x, 50), sf::Text("Zappy", _font, 50), std::string("Zappy"));
    Button background = Button(sf::RectangleShape(sf::Vector2f(windowSize.x -300, windowSize.y - 300)), sf::Vector2f(200, 100), sf::Text("", _font, 0), std::string("Z"));

    title.setColor(sf::Color::Black);
    background.setColor(sf::Color(45.1, 100, 98.4, 0));
    play.setColor(sf::Color(20.4, 60.4, 64.3, 255));
    setting.setColor(sf::Color(20.4, 60.4, 64.3, 255));

    addButton(play);
    addButton(setting);
    addButton(title);
}

void Menu::update(std::shared_ptr<Client> &, sf::RenderWindow &)
{
    for (auto &button : _buttonsMap) {
        if (button.second.getIsClick() == true) {
            if (button.second.getName() == "Play") {
                _switchScene = 2;
            }
            if (button.second.getName() == "Settings") {
                std::cout << "Settings" << std::endl;
            }
        }
    }
}

int Menu::getSwitchScene()
{
    return _switchScene;
}

void Menu::draw(sf::RenderWindow &window)
{
    for (const auto& pair : _spritesMap) {
        window.draw(pair.second);
    }
    for (const auto& pair : _buttonsMap) {
        window.draw(pair.second.getRectShape());
        window.draw(pair.second.getText());
    }
}

void Menu::handleEvent(sf::Event &event, sf::RenderWindow &window)
{
    sf::Vector2f worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            for (auto &button : _buttonsMap) {
                if (button.second.getRectShape().getGlobalBounds().contains(worldPos)) {
                    button.second.setIsClick(true);
                }
            }
        }
    }
    else if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            for (auto &button : _buttonsMap) {
                if (button.second.getRectShape().getGlobalBounds().contains(worldPos)) {
                    button.second.setIsClick(false);
                }
            }
        }
    }
}

void Menu::addSprite(std::string name, sf::Sprite sprite)
{
    _spritesMap[name] = sprite;
}

void Menu::addButton(Button &button)
{
    _buttonsMap.insert(std::pair<std::string, Button>(button.getName(), button));
}

void Menu::setSpriteMap(std::string map)
{
    SpriteFactory spriteFactory;
    float x = 0;
    float y = 0;
    int nbSprite = 0;

    for (auto symbol : map) {
        if (symbol == 'X') {
            sf::Vector2f spritePosition(x, y);
            sf::Sprite grassSprite = spriteFactory.createSprite("grass", spritePosition);
            addSprite("grass" + std::to_string(nbSprite), grassSprite);
            nbSprite++;
        }
        if (symbol == 'T') {
            sf::Vector2f spritePosition(x, y);
            sf::Sprite treeSprite = spriteFactory.createSprite("tree", spritePosition);
            addSprite("tree" + std::to_string(nbSprite), treeSprite);
            nbSprite++;
        }
        if (symbol == '\n') {
            x = 0;
            y += 16;
        } else {
            x += 16;
        }
    }
}

void Menu::animation(int)
{
}