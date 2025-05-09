/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGRUSH3-oscar.deschamps
** File description:
** info_block
*/

#ifndef INFO_BLOCK_HPP_
    #define INFO_BLOCK_HPP_
    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>

    class infoBlock
    {
        public:
            infoBlock(const sf::Vector2f &position, const sf::Vector2f &size);
            ~infoBlock();
            sf::RectangleShape getRec_back() const;
            sf::VertexArray getGraph() const;
            void setGraph(float value);
            void resetGraphPos();
            void setPosBlock(sf::Vector2f pos);
            sf::Vector2f getPosition();
            float x;
        private:
            sf::RectangleShape rec_back;
            sf::VertexArray graph;
            sf::Vector2f _position;
            sf::Vector2f _size;
            sf::Vertex vertex;
            float y;

    };


#endif /* !INFO_BLOCK_HPP_ */
