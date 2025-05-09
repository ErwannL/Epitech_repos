/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** Core
*/

#include "../include/Core.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"

void Core::run()
{
    int currentScene = NONE;
    WindowSFML window = WindowSFML("window", 1920, 1080);
    Camera camera(window.getWindow());
    window.switchScene("menu", new Menu(), this->client);

    while (window.getWindow().isOpen()) {
        if (window.getCurrentScene()->getSwitchScene() == GAME) {
            if (currentScene != GAME) {
                window.switchScene("Game", new Game(), this->client);
                currentScene = GAME;
                std::cout << "Running Game" << std::endl;
            }
            camera.update();
        }
        if (window.render(this->client) == false) break;
    }

    send(client.get()->getClient(), "/quit", strlen("/quit"), 0x0);
}
