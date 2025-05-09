/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD10-erwann.laplante
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
    #define FRUITBOX_HPP_

    #include "IFruit.hpp"
    #include "AFruit.hpp"
    #include <algorithm>
    #include <list>

    class FruitBox {
        public:
            FruitBox(unsigned int size);
            ~FruitBox();

            unsigned int getSize() const;
            unsigned int nbFruits() const;
            std::ostream &print(std::ostream &stream) const;

            bool pushFruit(IFruit *fruit);
            IFruit *popFruit();

        protected:
            unsigned int _size;
            unsigned int _nbr;
            std::list<IFruit *>_element;
    };

    std::ostream &operator<<(std::ostream &stream, FruitBox const &fruit);

#endif /* !FRUITBOX_HPP_ */
