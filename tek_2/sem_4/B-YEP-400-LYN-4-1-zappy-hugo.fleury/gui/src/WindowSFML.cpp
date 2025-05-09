/*
** EPITECH PROJECT, 2023
** gui
** File description:
** WindowSFML
*/

#include "WindowSFML.hpp"

WindowSFML::WindowSFML(std::string name, int width, int height)
{
    this->window.create(sf::VideoMode(width, height), name);
    this->window.setFramerateLimit(60);
    this->window.setActive(true);
    this->_currentScene = nullptr;
}

WindowSFML::~WindowSFML()
{
}

void WindowSFML::switchScene(std::string, IScene *scene, std::shared_ptr<Client> &client)
{
    if (this->_currentScene != nullptr)
        delete this->_currentScene;
    this->_currentScene = scene;
    this->_currentScene->init(this->window, client);
}

bool WindowSFML::render(std::shared_ptr<Client> &client)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        this->_currentScene->handleEvent(event, window);
        if (event.type == sf::Event::Closed) {
            window.close();
            return false;
        }
    }
    window.clear(sf::Color(46.3, 79.2, 42.7, 0));
    sf::Time elapsed = clock.restart();
    totalTime += elapsed.asSeconds();
    if (totalTime >= frameTime)
    {
        currentFrame = (currentFrame + 1);
        this->_currentScene->animation(currentFrame);
        totalTime -= frameTime;
    }
    this->_currentScene->update(client, window);
    this->_currentScene->draw(this->window);
    window.display();
    return true;
}

sf::RenderWindow &WindowSFML::getWindow()
{
    return (this->window);
}

IScene *WindowSFML::getCurrentScene()
{
    return (this->_currentScene);
}

void WindowSFML::setView(sf::View &view)
{
    window.setView(view);
}