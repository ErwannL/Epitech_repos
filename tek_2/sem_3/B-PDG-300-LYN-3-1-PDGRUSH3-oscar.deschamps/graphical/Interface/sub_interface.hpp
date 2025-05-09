/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGRUSH3-oscar.deschamps
** File description:
** sub-interface
*/

#ifndef SUB_INTERFACE_HPP_
    #define SUB_INTERFACE_HPP_
    #include "info_block.hpp"
    #include "CreateText.hpp"
    #include <list>

    class subInterface
    {
        public:
            subInterface(size_t nb_blocks, sf::Vector2f pos, sf::Vector2f _size, std::string name);
            ~subInterface();
            std::list<infoBlock> getBlocks() const;
            void addBlock();
            void removeBlock();
            void updateListGraph(float value);
            int getSize() const;
            sf::RectangleShape getRec_back();
            std::string getName() const;
            void setTextInterface();
            sf::Text getScale();
            void setGraphInterface(int nb_blocks);
            sf::Text getTime();
        private:
            std::list<infoBlock> list_blocks;
            std::string name;
            sf::Text scale;
            sf::Text time;
            sf::Font font;
            size_t size;
            sf::RectangleShape rec_back;
            float sizeBlocks;
    };
#endif /* !SUB_INTERFACE_HPP_ */
