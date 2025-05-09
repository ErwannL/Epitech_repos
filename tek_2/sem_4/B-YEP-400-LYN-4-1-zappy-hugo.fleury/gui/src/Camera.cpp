/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** Camera
*/

#include "Camera.hpp"

Camera::Camera(sf::RenderWindow& _window): window(_window),
    view(_window.getDefaultView()),
    cameraSpeed(25.0f),
    zoomFactor(1.0f),
    zoomSpeed(0.05f)
{
}

Camera::~Camera()
{
}

void Camera::update()
{
    handleInput();
    applyView();
}

void Camera::applyView()
{
    window.setView(view);
}

void Camera::resetCamera()
{
    view = window.getDefaultView();
}

float Camera::getAdjustedCameraSpeed()
{
    float adjustedSpeed = cameraSpeed * zoomFactor;

    return adjustedSpeed;
}

void Camera::handleInput()
{
    float zoom = view.getSize().x / window.getSize().x;
    float adjustedSpeed = getAdjustedCameraSpeed();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        view.move(-adjustedSpeed * zoomFactor, 0);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        view.move(adjustedSpeed * zoomFactor, 0);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        view.move(0, -adjustedSpeed * zoomFactor);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        view.move(0, adjustedSpeed * zoomFactor);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && zoom > 0.1f)
        view.zoom(1.0f - zoomSpeed);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        view.zoom(1.0f + zoomSpeed);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        resetCamera();
}
