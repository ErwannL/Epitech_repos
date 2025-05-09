/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_
    #include <SFML/Graphics.hpp>
    #include <iostream>
    class Camera
    {
        public:
            Camera(sf::RenderWindow& window);
            ~Camera();
            void update();

        private:
            void handleInput();
            void applyView();
            void resetCamera();
            float getAdjustedCameraSpeed();

        private:
            sf::RenderWindow& window;
            sf::View view;
            float cameraSpeed;
            float zoomFactor;
            float zoomSpeed;
    };

#endif /* !CAMERA_HPP_ */
