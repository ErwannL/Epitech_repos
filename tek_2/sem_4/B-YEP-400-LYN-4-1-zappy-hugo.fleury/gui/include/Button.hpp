/*
** EPITECH PROJECT, 2023
** B-YEP-400-LYN-4-1-zappy-hugo.fleury
** File description:
** Button
*/

#ifndef BUTTON_HPP_
    #define BUTTON_HPP_
    #include <SFML/Graphics.hpp>
    #include <iostream>

    class Button {
        public:
            Button(sf::RectangleShape, sf::Vector2f, sf::Text, std::string);
            ~Button();
            void update() {};
            void draw(sf::RenderWindow &) {};

            bool collide() {return isCollide;};
            bool isClicked() {return isClick;};
            bool isHovered() {return isHover;};

            void setTexture(std::string) {};
            void setText(std::string) {};
            void setString(std::string) {};
            void setFont(std::string) {};

            void setRectShape(sf::RectangleShape) {}
            void setPos(int , int) {};
            void setOrigin(int, int) {};
            void setScale(int) {};
            void setRotation(int) {};
            void setName(std::string) {};
            void setIsHover(bool) {};
            void setIsClick(bool);
            void setColor(sf::Color color);

            sf::Vector2f getPosition() const {return _RectShape.getPosition();};
            void getOrigin() const {};
            sf::RectangleShape getRectShape() const;
            sf::Text getText() const;
            sf::Font getFont() const {return _font;};
            std::string getName() const;
            bool getIsHover() const {return isHover;};
            bool getIsClick() const {return isClick;};
            bool getisCOllide() const {return isCollide;};

            Button &operator=(const Button &other) {
                this->_RectShape = other.getRectShape();
                this->_text = other.getText();
                this->_font = other.getFont();
                this->_name = other.getName();
                this->isHover = other.getIsHover();
                this->isClick = other.getIsClick();
                this->isCollide = other.getisCOllide();
                return *this;
            };
        protected:
            sf::Color _defaultColor;
            sf::RectangleShape _RectShape;
            sf::Text _text;
            sf::Font _font;
            std::string _name;
            bool isHover = false;
            bool isClick = false;
            bool isCollide = false;
        private:
    };

#endif /* !BUTTON_HPP_ */
