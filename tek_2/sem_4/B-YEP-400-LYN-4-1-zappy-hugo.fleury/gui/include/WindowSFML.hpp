/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Window
*/

#ifndef WINDOW_HPP_
    #define WINDOW_HPP_
    #include "IScene.hpp"
    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    #include <memory>

    class WindowSFML {
        public:
            WindowSFML(std::string, int, int);
            ~WindowSFML();
            bool render(std::shared_ptr<Client> &client);
            void switchScene(std::string, IScene *, std::shared_ptr<Client> &client);
            sf::RenderWindow &getWindow();
            IScene *getCurrentScene();
            void setView(sf::View &view);
        protected:
            sf::Vector2i frameSize;
            int currentFrame = 0;
            float frameTime = 0.1f;
            float totalTime = 0.f;
            sf::Clock clock;

            IScene *_currentScene = nullptr;
            std::map<std::string, sf::Sprite> mapSprites;
            sf::RenderWindow window;
            std::shared_ptr<Client> _client;
            int left;
        private:
    };

#endif /* !WINDOW_HPP_ */
